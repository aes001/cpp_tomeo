#ifndef NAVBUTTONS_H
#define NAVBUTTONS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QUrl>
#include <QPixmap>
#include <QMouseEvent>
#include "constants.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class navButtons: public QWidget
{
    Q_OBJECT
public:
    navButtons(QWidget *parent = nullptr);

private:
    QPushButton *myProfileButtonContainer;
    QPushButton *recordVideoButtonContainer;
    QPushButton *myFriendsButtonContainer;

signals:
    void myProfileButtonClicked();
    void recordVideoButtonClicked();
    void myFriendsButtonClicked();

public slots:
    void myProfileButtonClickedSlot();
    void recordVideoButtonClickedSlot();
    void myFriendsButtonClickedSlot();
};

#endif // NAVBUTTONS_H
