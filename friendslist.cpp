#include "friendslist.h"
#include "ui_friendslist.h"

FriendsList::FriendsList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendsList)
{
    ui->setupUi(this);
}

FriendsList::~FriendsList()
{
    delete ui;
}
