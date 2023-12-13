#include "friendslist.h"
#include "ui_friendslist.h"

FriendsList::FriendsList(QWidget *parent) : QWidget(parent), ui(new Ui::FriendsList)
{
    ui->setupUi(this);
}

FriendsList::~FriendsList()
{
    delete ui;
}

void FriendsList::on_backButton_clicked()
{
    DEBUG_MSG("FriendsList: Back button clicked")
    emit backButtonClicked();
}

