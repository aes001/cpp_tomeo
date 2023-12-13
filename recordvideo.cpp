#include "recordvideo.h"
#include "ui_recordvideo.h"

recordVideo::recordVideo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recordVideo)
{
    ui->setupUi(this);
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
}

recordVideo::~recordVideo()
{
    delete ui;
}

void recordVideo::on_backButton_clicked()
{
    DEBUG_MSG("recordVideo: Back button clicked")
    emit backButtonClicked();
}
