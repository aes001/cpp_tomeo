#ifndef RECORDVIDEO_H
#define RECORDVIDEO_H

#include <QWidget>

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
};

#endif // RECORDVIDEO_H
