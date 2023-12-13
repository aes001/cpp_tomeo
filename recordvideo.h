#ifndef RECORDVIDEO_H
#define RECORDVIDEO_H

#include <QWidget>
#include "constants.h"

namespace Ui {
class recordVideo;
}

class recordVideo : public QWidget
{
    Q_OBJECT

public:
    explicit recordVideo(QWidget *parent = nullptr);
    ~recordVideo();

private:
    Ui::recordVideo *ui;

signals:
    void backButtonClicked();

private slots:
    void on_backButton_clicked();
};

#endif // RECORDVIDEO_H
