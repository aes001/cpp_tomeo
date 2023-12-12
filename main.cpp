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
#include "navbuttons.h"
#include "friendslist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the stacked widget and add the pages
    mainPagesViews *theWindow = new mainPagesViews();

    theWindow->show();

    // For debugging purposes
    int currentStackIndex = theWindow->currentIndex();
    QString currentStackIndexString = QString::number(currentStackIndex);
    qDebug() << "Window: " << currentStackIndexString;

    return a.exec();
}
