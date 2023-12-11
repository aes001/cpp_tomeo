#include "videoplayer.h"

videoPlayer::videoPlayer(QUrl videoUrl, QWidget *parent) : QVideoWidget(parent), videoUrl(videoUrl){
    player = new QMediaPlayer;
    player->setVideoOutput(this);
    player->setMedia(videoUrl);
    player->setVolume(0);

    // Wait for the video to load and then we can resize the player
    // QT Loads the video asynchronously, so we need to wait for it to load before we can resize the player
    connect(player, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), this, SLOT(resizePlayer()));

    // Ensure we resize the player before playing the video
    connect(this, SIGNAL(windowResized()), player, SLOT(pause()));

    // Make the video loop
    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(playStateChanged(QMediaPlayer::State)));

    // Make the video pause when clicked
    connect(this, SIGNAL(clicked()), this, SLOT(togglePlay()));
}

void videoPlayer::playStateChanged(QMediaPlayer::State state){
    if (state == QMediaPlayer::StoppedState){
        player->play();
    }
}

void videoPlayer::togglePlay(){
    //DEBUG_MSG("Toggle Play\n")
    QMediaPlayer::State state = player->state();
    if (state == QMediaPlayer::PlayingState){
        player->pause();
    } else {
        player->play();
    }
}

void videoPlayer::mousePressEvent(QMouseEvent *event){
    Q_UNUSED(event);
    emit clicked();
}

// Resize the video player to the aspect ratio of the video
void videoPlayer::resizePlayer(){
    if (!resized){ // Only resize once
        if(player->isMetaDataAvailable()){ // Ensure metadata is available
            QVariant resolution = player->metaData("Resolution");
            if (resolution.isValid()){ // Ensure metadata is valid
                float originalWidth = resolution.toSizeF().width();
                float originalHeight = resolution.toSizeF().height();

                DEBUG_MSG("Video: " << videoUrl << "\n" << "Resolution: " << originalWidth << "x" << originalHeight << "\n")

                setMaximumHeight(std::ceil((APP_WIDTH/originalWidth)*originalHeight));
                setMaximumWidth(APP_WIDTH);
                setMinimumHeight(std::ceil((APP_WIDTH/originalWidth)*originalHeight));
                setMinimumWidth(APP_WIDTH);

                resized = true; // Don't resize again
                emit windowResized(); // Tell the player to play the video
            } else {
                qDebug() << "Resize failed: Invalid metadata.\n Skipping Video.";
                // exit(-1);
            }
        } else {
            qDebug() << "Resize failed: Unavailable metadata.\n Skipping video.";
            // exit(-1);
        }
    }
}

QString videoPlayer::getVideoName(){
    return videoUrl.fileName();
}
