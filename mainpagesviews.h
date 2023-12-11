#ifndef MAINPAGESVIEWS_H
#define MAINPAGESVIEWS_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include "constants.h"
#include "mainwindow.h"


// To Do: might be a good idea to make this a singleton
class mainPagesViews : public QStackedWidget
{
    Q_OBJECT
public:
    mainPagesViews(QWidget *parent = nullptr);

public slots:
    void on_loginClicked();
};

#endif // MAINPAGESVIEWS_H
