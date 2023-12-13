#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>
#include <QWidget>
#include <QUrl>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <iostream>
#include <cmath>
#include "constants.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QIcon>

/**
 * A video player widget that can be added to a layout
 * This video player will automatically resize to the aspect ratio of the video and loop the video
 * The video will play when clicked and pause when clicked again
 *
 * @param videoUrl: the url of the video to play
 * @param parent: the parent widget, defaults to nullptr see note below
 *
 * @example videoPlayer *v = new videoPlayer(QUrl::fromLocalFile("path/to/video.mp4"), parent);
*/
class videoPlayer: public QVideoWidget
{
    Q_OBJECT
public:
    videoPlayer(QUrl videoUrl, QWidget *parent = nullptr);
    QString getVideoName();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    QMediaPlayer *player;
    QUrl videoUrl;
    bool resized = false;

public slots:
    void resizePlayer();
    void playStateChanged(QMediaPlayer::State state);
    void togglePlay();

signals:
    void windowResized();
    void clicked();
};

#endif // VIDEOPLAYER_H
