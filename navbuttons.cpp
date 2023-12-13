#include "navbuttons.h"
#include "qdebug.h"

navButtons::navButtons(QWidget *parent): QWidget(parent)
{
    QHBoxLayout *homeButtonLayout = new QHBoxLayout();
    homeButtonLayout->setContentsMargins(0, 0, 0, 0);
    homeButtonLayout->setAlignment(Qt::AlignBottom);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setLayout(homeButtonLayout);

    // My Profile Button
    // I don't know of a better way to do this...
    myProfileButtonContainer = new QPushButton(this); // Container for the button and label
    QVBoxLayout *myProfileButtonLayout = new QVBoxLayout();
    myProfileButtonLayout->setContentsMargins(0, 0, 0, 0);
    myProfileButtonLayout->setAlignment(Qt::AlignCenter);
    myProfileButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    myProfileButtonContainer->sizeHint().height();
    myProfileButtonContainer->setLayout(myProfileButtonLayout);
    myProfileButtonContainer->setFlat(true);
    QLabel *myProfileButtonLabel = new QLabel("My Profile", this);
    QLabel *myProfileButton = new QLabel(this);
    myProfileButtonLabel->setAlignment(Qt::AlignHCenter);
    myProfileButtonLabel->setContentsMargins(0, 0, 0, 0);
    QPixmap pic = QPixmap(":/Assets/profile_icon.svg");
    pic = pic.scaled(APP_WIDTH/8, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    myProfileButton->setPixmap(pic);
    myProfileButton->setAlignment(Qt::AlignCenter);
    myProfileButtonContainer->setContentsMargins(0, 0, 0, 0);
    myProfileButtonContainer->setFixedSize(myProfileButton->sizeHint() + myProfileButtonLabel->sizeHint() + QSize(0, 8)); // Truly truly awful nightmare I don't know why I have to do it like this
    myProfileButtonContainer->adjustSize();
    myProfileButtonLayout->addWidget(myProfileButton);
    myProfileButtonLayout->addWidget(myProfileButtonLabel);
    homeButtonLayout->addWidget(myProfileButtonContainer);

    // Add spacer between the center button
    QSpacerItem *centerSpacerL = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    homeButtonLayout->addItem(centerSpacerL);

    // Add Video Button
    recordVideoButtonContainer = new QPushButton(this); // Container for the button and label
    QVBoxLayout *recordVideoButtonLayout = new QVBoxLayout();
    recordVideoButtonLayout->setContentsMargins(0, 0, 0, 0);
    recordVideoButtonLayout->setAlignment(Qt::AlignCenter);
    recordVideoButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    recordVideoButtonContainer->sizeHint().height();
    recordVideoButtonContainer->setLayout(recordVideoButtonLayout);
    recordVideoButtonContainer->setFlat(true);
    QLabel *recordVideoButtonLabel = new QLabel("Add Video", this);
    QLabel *recordVideoButton = new QLabel(this);
    recordVideoButtonLabel->setAlignment(Qt::AlignHCenter);
    recordVideoButtonLabel->setContentsMargins(0, 0, 0, 0);
    pic = QPixmap(":/Assets/record_cam_button.svg");
    pic = pic.scaled(APP_WIDTH/8, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    recordVideoButton->setPixmap(pic);
    recordVideoButton->setAlignment(Qt::AlignCenter);
    recordVideoButtonContainer->setContentsMargins(0, 0, 0, 0);
    recordVideoButtonContainer->setFixedSize(recordVideoButton->sizeHint() + recordVideoButtonLabel->sizeHint() + QSize(0, 8));
    recordVideoButtonContainer->adjustSize();
    recordVideoButtonLayout->addWidget(recordVideoButton);
    recordVideoButtonLayout->addWidget(recordVideoButtonLabel);
    homeButtonLayout->addWidget(recordVideoButtonContainer);

    // Add spacer between the center button
    QSpacerItem *centerSpacerR = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    homeButtonLayout->addItem(centerSpacerR);

    // Friends Button
    myFriendsButtonContainer = new QPushButton(this); // Container for the button and label
    QVBoxLayout *myFriendsButtonLayout = new QVBoxLayout();
    myFriendsButtonLayout->setContentsMargins(0, 0, 0, 0);
    myFriendsButtonLayout->setAlignment(Qt::AlignCenter);
    myFriendsButtonContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    myFriendsButtonContainer->sizeHint().height();
    myFriendsButtonContainer->setLayout(myFriendsButtonLayout);
    myFriendsButtonContainer->setFlat(true);
    QLabel *myFriendsButtonLabel = new QLabel("Friends", this);
    QLabel *myFriendsButton = new QLabel(this);
    myFriendsButtonLabel->setAlignment(Qt::AlignHCenter);
    myFriendsButtonLabel->setContentsMargins(0, 0, 0, 0);
    pic = QPixmap(":/Assets/friends_fancy.svg");
    pic = pic.scaled(99999, APP_WIDTH/8, Qt::KeepAspectRatio, Qt::SmoothTransformation); // Set the width to a realy big number so the height is the only thing that matters
    myFriendsButton->setPixmap(pic);
    myFriendsButton->setAlignment(Qt::AlignCenter);
    myFriendsButtonContainer->setContentsMargins(0, 0, 0, 0);
    myFriendsButtonContainer->setFixedSize(myFriendsButton->sizeHint() + myFriendsButtonLabel->sizeHint() + QSize(0, 8));
    myFriendsButtonContainer->adjustSize();
    myFriendsButtonLayout->addWidget(myFriendsButton);
    myFriendsButtonLayout->addWidget(myFriendsButtonLabel);
    homeButtonLayout->addWidget(myFriendsButtonContainer);

    // Connect the buttons to the slots
    connect(myProfileButtonContainer, SIGNAL(clicked(bool)), this, SLOT(myProfileButtonClickedSlot()));
    connect(recordVideoButtonContainer, SIGNAL(clicked(bool)), this, SLOT(recordVideoButtonClickedSlot()));
    connect(myFriendsButtonContainer, SIGNAL(clicked(bool)), this, SLOT(myFriendsButtonClickedSlot()));
}


void navButtons::myProfileButtonClickedSlot()
{
    DEBUG_MSG("My Profile Button Clicked!")
    emit myProfileButtonClicked();
}

void navButtons::recordVideoButtonClickedSlot()
{
    DEBUG_MSG("Record Video Button Clicked!")
    emit recordVideoButtonClicked();
}

void navButtons::myFriendsButtonClickedSlot()
{
    DEBUG_MSG("My Friends Button Clicked!")
    emit myFriendsButtonClicked();
}
