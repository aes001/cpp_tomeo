#include "registerform.h"
#include "ui_registerform.h"
#include <QMessageBox>


RegisterForm::RegisterForm(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterForm){
    ui->setupUi(this);
}

RegisterForm::~RegisterForm(){
    delete ui;
}

void RegisterForm::on_loginBtn_clicked(){
   this->close(); // This will close the RegisterForm dialog
}

void RegisterForm::on_ConfirmRegBtn_clicked(){
   QString username = ui->usernameEntry1->text();
   QString password = ui->passentry1->text();
   QString confirmPassword = ui->confirm_pass1->text();

   if (username.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
       QMessageBox::warning(this, "Input Error", "Username and password fields cannot be empty.", QMessageBox::Ok);
       return;
   }

   if (password != confirmPassword) {
       QMessageBox::warning(this, "Input Error", "The passwords do not match.", QMessageBox::Ok);
       return;
   }

   ui->usernameEntry1->clear();
   ui->passentry1->clear();
   ui->confirm_pass1->clear();

   QMessageBox::information(this, "Registration", "Registration successful.", QMessageBox::Ok);
}

void RegisterForm::on_privacy_clicked(){
    QMessageBox::information(this, "Privacy Policy", "This shows the privacy policy", QMessageBox::Ok);
}

