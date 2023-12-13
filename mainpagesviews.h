#ifndef MAINPAGESVIEWS_H
#define MAINPAGESVIEWS_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "constants.h"
#include "mainwindow.h"
#include "homevideos.h"
#include "friendprofile.h"
#include "friendslist.h"
#include "recordvideo.h"


// To Do: might be a good idea to make this a singleton
// This is the widget that holds all the pages and is essentially the main window
class mainPagesViews : public QStackedWidget
{
    Q_OBJECT
public:
    mainPagesViews(QWidget *parent = nullptr);

public slots:
    void on_loginClicked();
    void on_myProfileClicked();
    void on_friendsListClicked();
    void on_recordVideoClicked();
    void on_logoutClicked();
};

#endif // MAINPAGESVIEWS_H
