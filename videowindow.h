#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QObject>
#include <QWidget>
#include <QVideoWidget>

class videoWindow : public QVideoWidget
{
    Q_OBJECT
public:
    explicit videoWindow(QWidget *parent = nullptr);

signals:
    void resizeWindow();

};

#endif // VIDEOWINDOW_H
