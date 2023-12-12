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

    // Add the home page
    homeVideos *homePage = new homeVideos();
    homePage->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    homePage->setMinimumSize(APP_WIDTH, APP_HEIGHT);


    this->addWidget(homePage);

    // Add the profile page
    FriendProfile *profilePage = new FriendProfile();
    profilePage->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    profilePage->setMinimumSize(APP_WIDTH, APP_HEIGHT);

    connect(homePage, SIGNAL(myProfileClicked()), this, SLOT(on_myProfileClicked()));
    connect(profilePage, SIGNAL(backButtonClicked()), this, SLOT(on_loginClicked()));

    this->addWidget(profilePage);

    // Add the friends list page
    FriendsList *friendsListPage = new FriendsList();
    friendsListPage->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    friendsListPage->setMinimumSize(APP_WIDTH, APP_HEIGHT);

    connect(homePage, SIGNAL(myFriendsClicked()), this, SLOT(on_friendsListClicked()));
    connect(friendsListPage, SIGNAL(backButtonClicked()), this, SLOT(on_loginClicked()));

    this->addWidget(friendsListPage);
}

void mainPagesViews::on_loginClicked()
{
    this->setCurrentIndex(1);
}

void mainPagesViews::on_myProfileClicked()
{
    this->setCurrentIndex(2);
}

void mainPagesViews::on_friendsListClicked()
{
    this->setCurrentIndex(3);
}
