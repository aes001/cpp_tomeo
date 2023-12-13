#include "recordvideo.h"
#include "ui_recordvideo.h"

recordVideo::recordVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recordVideo)
{
    ui->setupUi(this);
}

recordVideo::~recordVideo()
{
    delete ui;
}
