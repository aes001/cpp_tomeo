#include "friendprofile.h"
#include "ui_friendprofile.h"

FriendProfile::FriendProfile(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FriendProfile)
{
    ui->setupUi(this);

    // user profile is true if what is being displayed is a user profile, or false if its a friend profile
    bool userProfile = false;

    // this stores the user information to be displayed on the user interface
    // these could be changed to classes with values for the relevant fields
    QString userInfo[5] = {"sc22j3h", "C:\\Users\\User\\OneDrive\\Desktop\\User Interface\\CWK1\\Week2\\FriendProfle\\profilePic.png", "Hello, my name is James and I'm using TOMEO!", "videoLocation.mp4", "friendName"};
    QString friendInfo[5] = {"Kevin Heart", "C:\\Users\\User\\OneDrive\\Desktop\\User Interface\\CWK1\\Week2\\FriendProfle\\kevinHeart.png", "I'm Kevin Heart and this is my TOMEO BIO", "videoLocation.mp4", "mutualFriendName"};

    if(userProfile)
    {
        ui->userName->setText(userInfo[0]);
        ui->profileImage->setPixmap(QPixmap(userInfo[1]));
        ui->bioText->setText(userInfo[2]);
    }
    else
    {
        ui->userName->setText(friendInfo[0]);
        ui->profileImage->setPixmap(QPixmap(friendInfo[1]));
        ui->bioText->setText(friendInfo[2]);

        ui->userFriends->setText("Mutual Friends:");
        ui->userVideos->setText("Top Videos:");
    }
}
FriendProfile::~FriendProfile()
{
    delete ui;
}
