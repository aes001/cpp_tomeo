#include "mainwindow.h"
#include "registerform.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: #FFFFFF;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_registerBtn_clicked()
{
    RegisterForm registerDialog(this); // Pass 'this' to set MainWindow as the parent
    registerDialog.exec(); // Show the dialog as a modal window
}

void MainWindow::on_privacy_clicked()
{
    QMessageBox::information(this, "Privacy Policy", "This shows the privacy policy", QMessageBox::Ok);
}
