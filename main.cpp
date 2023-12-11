#include <QApplication>
#include <QLabel>
#include <QtWidgets/QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include "constants.h"
#include "videoplayer.h"
#include <iostream>
#include "readvideos.h"
#include <QMessageBox>
#include <QScrollArea>
#include <QStackedWidget>
#include "mainwindow.h"
#include "mainpagesviews.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::vector<videoPlayer*> videos;

    if (argc == 2)
        // videos = readVideos(std::string(argv[1]));
        videos = readVideos("../tomeo4/videos");

    if (videos.size() == 0) {
        QMessageBox::information(
            NULL,
            QString("Tomeo"),
            QString("No videos found! Add command line argument to \"quoted\" file location."));
        exit(-1);
    }

    // Once we have verified that we have videos, we can create the window and layout

    QWidget *viewVideosWindow = new QWidget();
    viewVideosWindow->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    viewVideosWindow->setMinimumSize(APP_WIDTH, APP_HEIGHT);
    viewVideosWindow->setWindowTitle("Tomeo");

    QVBoxLayout *layout = new QVBoxLayout();

    QScrollArea *scrollArea = new QScrollArea(viewVideosWindow);
    QWidget *scrollAreaWidgetContents = new QWidget(scrollArea);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollAreaWidgetContents->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel *header = new QLabel("My Videos", viewVideosWindow);
    header->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    QFont font = header->font();
    font.setPointSize(18);
    font.setBold(true);
    header->setFont(font);
    header->setAlignment(Qt::AlignHCenter);

    // Add the videos to the layout
    for (int i = 0; i < (int) videos.size(); i++) {

        // Set the video parent to the window as stated in the note in readvideos.cpp
        videos.at(i)->setParent(viewVideosWindow);

        // Create the video name label
        QLabel *videoName = new QLabel(videos.at(i)->getVideoName(), viewVideosWindow);
        QFont videoNameFont = videoName->font();
        videoNameFont.setPointSize(10);
        videoNameFont.setBold(true);
        videoName->setFont(videoNameFont);

        // Cretae a horizontal layout for the video name so we can add a little space before it
        QHBoxLayout *videoTitleLayout = new QHBoxLayout();
        QSpacerItem *titleSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
        videoTitleLayout->setContentsMargins(0, 0, 0, 0);
        videoTitleLayout->setAlignment(Qt::AlignHCenter);
        videoTitleLayout->addItem(titleSpacer);
        videoTitleLayout->addWidget(videoName);

        QWidget *videoTitleContainer = new QWidget(viewVideosWindow);
        videoTitleContainer->setLayout(videoTitleLayout);

        layout->addWidget(videoTitleContainer);
        layout->addWidget(videos.at(i));



////        QWidget *playButtonTest = new QWidget(window);
//        QVBoxLayout *videoControlsLayout = new QVBoxLayout();

//        QWidget *playButtonContainer = new QWidget(videos.at(i));
//        QHBoxLayout *playButtonLayout = new QHBoxLayout();
//        playButtonLayout->setContentsMargins(0, 0, 0, 0);
//        playButtonLayout->setAlignment(Qt::AlignCenter);
//        playButtonContainer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//        videoControlsLayout->addWidget(playButtonContainer);
//        playButtonContainer->setLayout(playButtonLayout);
//        QLabel *playButton = new QLabel(playButtonContainer);
//        QPixmap pic = QPixmap("C:\\Users\\aesun\\Documents\\Tasks and Homeworks\\Uni 21\\User Interfaces\\Tomeo 4\\Tomeo4\\Assets\\play.png");
//        pic = pic.scaled(APP_WIDTH/5, APP_WIDTH/5, Qt::KeepAspectRatio);
//        playButton->setPixmap(pic);
//        playButton->setAlignment(Qt::AlignCenter);
//        videoControlsLayout->addWidget(playButton);

//        videoControlsLayout->setContentsMargins(0, 0, 0, 0);

//        videos.at(i)->setLayout(videoControlsLayout);


        QSpacerItem *spacer = new QSpacerItem(0, VIDEO_SPACING_HEIGHT, QSizePolicy::Minimum, QSizePolicy::Expanding);
        layout->addItem(spacer);
    }

    // Row of buttons at the bottom
    QWidget *homeButtonContainer = new QWidget(viewVideosWindow);
    QHBoxLayout *homeButtonLayout = new QHBoxLayout();
    homeButtonLayout->setContentsMargins(0, 0, 0, 0);
    homeButtonLayout->setAlignment(Qt::AlignBottom);
    homeButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    homeButtonContainer->setLayout(homeButtonLayout);

    // My Profile Button
    QWidget *myProfileButtonContainer = new QWidget(homeButtonContainer); // Container for the button and label
    QVBoxLayout *myProfileButtonLayout = new QVBoxLayout();
    myProfileButtonLayout->setContentsMargins(0, 0, 0, 0);
    myProfileButtonLayout->setAlignment(Qt::AlignHCenter);
    myProfileButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    myProfileButtonContainer->setLayout(myProfileButtonLayout);
    QLabel *myProfileButtonLabel = new QLabel("My Profile", homeButtonContainer);
    QLabel *myProfileButton = new QLabel(homeButtonContainer);
    QPixmap pic = QPixmap(":/Assets/profile_icon.svg");
    pic = pic.scaled(APP_WIDTH/8, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    myProfileButton->setPixmap(pic);
    myProfileButton->setAlignment(Qt::AlignCenter);
    myProfileButtonLayout->addWidget(myProfileButtonLabel);
    myProfileButtonLayout->addWidget(myProfileButton);
    homeButtonLayout->addWidget(myProfileButtonContainer);

    // Add spacer between the center button
    QSpacerItem *centerSpacerL = new QSpacerItem(30, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    homeButtonLayout->addItem(centerSpacerL);

    // Add Video Button
    QWidget *addVideoButtonContainer = new QWidget(homeButtonContainer); // Container for the button and label
    QVBoxLayout *addVideoButtonLayout = new QVBoxLayout();
    addVideoButtonLayout->setContentsMargins(0, 0, 0, 0);
    myProfileButtonLayout->setAlignment(Qt::AlignHCenter);
    addVideoButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    addVideoButtonContainer->setLayout(addVideoButtonLayout);
    QLabel *addVideoButtonLabel = new QLabel("Add Video", homeButtonContainer);
    QLabel *addVideoButton = new QLabel(homeButtonContainer);
    pic = QPixmap(":/Assets/record_video_dark.svg");
    pic = pic.scaled(APP_WIDTH/8, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    addVideoButton->setPixmap(pic);
    addVideoButton->setAlignment(Qt::AlignHCenter);
    addVideoButtonLayout->addWidget(addVideoButtonLabel);
    addVideoButtonLayout->addWidget(addVideoButton);
    homeButtonLayout->addWidget(addVideoButtonContainer);

    // Add spacer between the center button
    QSpacerItem *centerSpacerR = new QSpacerItem(30, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    homeButtonLayout->addItem(centerSpacerR);

    // Friends Button
    QWidget *friendsButtonContainer = new QWidget(homeButtonContainer); // Container for the button and label
    QVBoxLayout *friendsButtonLayout = new QVBoxLayout();
    friendsButtonLayout->setContentsMargins(0, 0, 0, 0);
    myProfileButtonLayout->setAlignment(Qt::AlignHCenter);
    friendsButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    friendsButtonContainer->setLayout(friendsButtonLayout);
    QLabel *friendsButtonLabel = new QLabel("Friends", homeButtonContainer);
    QLabel *friendsButton = new QLabel(homeButtonContainer);
    pic = QPixmap(":/Assets/friends_fancy.svg");
    pic = pic.scaled(13841, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    friendsButton->setPixmap(pic);
    friendsButton->setAlignment(Qt::AlignCenter);
    friendsButtonLayout->addWidget(friendsButtonLabel);
    friendsButtonLayout->addWidget(friendsButton);
    homeButtonLayout->addWidget(friendsButtonContainer);


    QVBoxLayout *mainLayout = new QVBoxLayout(viewVideosWindow);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(header);
    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(homeButtonContainer);

    QSpacerItem *bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addItem(bottomSpacer);

    viewVideosWindow->setLayout(mainLayout);

    // Create the stacked widget and add the pages
    mainPagesViews *theWindow = new mainPagesViews();

    theWindow->addWidget(viewVideosWindow);


    theWindow->show();

    int currentStackIndex = theWindow->currentIndex();
    QString currentStackIndexString = QString::number(currentStackIndex);
    qDebug() << "Window: " << currentStackIndexString;
    //window->show();
    return a.exec();
}
