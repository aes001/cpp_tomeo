#ifndef HOMEVIDEOS_H
#define HOMEVIDEOS_H

#include <QWidget>
#include <QObject>
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
#include "navbuttons.h"


class homeVideos : public QWidget
{
    Q_OBJECT
public:
    homeVideos(QWidget *parent = nullptr);

public slots:
    void myProfileClickedSlot();
    void recordVideoClickedSlot();
    void myFriendsClickedSlot();

signals:
    void myProfileClicked();
    void recordVideoClicked();
    void myFriendsClicked();
};

#endif // HOMEVIDEOS_H
