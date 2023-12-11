#ifndef NAVBUTTONS_H
#define NAVBUTTONS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QUrl>
#include <QPixmap>
#include <QMouseEvent>
#include "constants.h"

class navButtons: public QLabel
{
    Q_OBJECT
public:
    navButtons(QUrl iconURL, int width_size_ratio, QWidget *parent = nullptr);

private:
    QUrl iconURL;
};

#endif // NAVBUTTONS_H
