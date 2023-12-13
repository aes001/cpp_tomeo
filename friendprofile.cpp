#include "friendprofile.h"
#include "ui_friendprofile.h"

FriendProfile::FriendProfile(QWidget *parent) : QMainWindow(parent), ui(new Ui::FriendProfile)
{
    ui->setupUi(this);

    // user profile is true if what is being displayed is a user profile, or false if its a friend profile
    bool userProfile = true;

    // this stores the user information to be displayed on the user interface
    // these could be changed to classes with values for the relevant fields
    QString userInfo[6] = {"sc22j3h",
                           ":/Assets/freindProfile3.png",
                           "Hello, my name is James and I'm using TOMEO!",
                           ":/Assets/videoThumbnail1.jpg",
                           ":/Assets/videoThumbnail2.jpg",
                           ":/Assets/videoThumbnail3.jpg"};

    QString friendInfo[6] = {"Kevin Heart",
                             ":/Assets/friendProfile2.png",
                             "I'm Kevin Heart and this is my TOMEO BIO",
                             ":/Assets/thumbnail_k01.jpg",
                             ":/Assets/thumbnail_k02.jpg",
                             ":/Assets/thumbnail_k03.jpg"};

    // Check if the user profile picture exists
    QString imageLocation = (userProfile) ? userInfo[1] : friendInfo[1];
    QFileInfo checkFile(imageLocation);
    if(checkFile.exists() && checkFile.isFile())
    {
        DEBUG_MSG("FriendProfile: File exists\n" << "Is file relative?" << checkFile.isRelative() << "\n")
    }
    else
    {
        DEBUG_MSG("FriendProfile: File does not exist\n")
        imageLocation = QString(":/Assets/profile_picture_placeholder.png");
    }

    // Set the user information on the user interface
    if(userProfile)
    {
        ui->userName->setText(userInfo[0]);
        ui->profileImage->setPixmap(QPixmap(imageLocation));
        ui->bioText->setText(userInfo[2]);

        // Set the video thumbnails
        ui->video_thumb1->setPixmap(QPixmap(userInfo[3]));
        ui->video_thumb2->setPixmap(QPixmap(userInfo[4]));
        ui->video_thumb3->setPixmap(QPixmap(userInfo[5]));
    }
    else
    {
        ui->userName->setText(friendInfo[0]);
        ui->profileImage->setPixmap(QPixmap(imageLocation));
        ui->bioText->setText(friendInfo[2]);
        ui->userVideos->setText("Top Videos:");

        // Set the video thumbnails
        ui->video_thumb1->setPixmap(QPixmap(friendInfo[3]));
        ui->video_thumb2->setPixmap(QPixmap(friendInfo[4]));
        ui->video_thumb3->setPixmap(QPixmap(friendInfo[5]));
    }


    connect(ui->backButton, &QPushButton::clicked, this, &FriendProfile::on_backButton_clicked);
    connect(ui->logOutButton, &QPushButton::clicked, this, &FriendProfile::on_logoutButton_clicked);
}

FriendProfile::~FriendProfile()
{
    delete ui;
}

void FriendProfile::on_backButton_clicked()
{
    DEBUG_MSG("FriendProfile: Back button clicked\n")
    emit backButtonClicked();
}

void FriendProfile::on_logoutButton_clicked()
{
    DEBUG_MSG("FriendProfile: Logout button clicked\n")
    emit logoutButtonClicked();
}
