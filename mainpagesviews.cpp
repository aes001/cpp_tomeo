#include "mainpagesviews.h"
#include "ui_mainwindow.h"

mainPagesViews::mainPagesViews(QWidget *parent) : QStackedWidget(parent)
{
    this->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    this->setMinimumSize(APP_WIDTH, APP_HEIGHT);
    this->setWindowTitle("Tomeo");

    // Add the login page
    MainWindow *loginPage = new MainWindow();
    loginPage->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    loginPage->setMinimumSize(APP_WIDTH, APP_HEIGHT);

    connect(loginPage->ui->LoginBtn, &QPushButton::clicked, this, &mainPagesViews::on_loginClicked);

    this->addWidget(loginPage);

}

void mainPagesViews::on_loginClicked()
{
    this->setCurrentIndex(1);
}
