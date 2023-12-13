#include "homevideos.h"

homeVideos::homeVideos(QWidget *parent) : QWidget(parent)
{
    std::vector<videoPlayer*> videos;

    // Uncomment the line below to pass in videos from the command line and then comment out the line below it.
    // videos = readVideos(std::string(argv[1]));
    videos = readVideos("../UI_tomeo/videos");

    // If we have no videos, error and exit
    if (videos.size() == 0) {
        QMessageBox::information(NULL, QString("Tomeo"), QString("No videos found! Please make sure there are videos in the path provided"));
        exit(-1);
    }

    // Once we have verified that we have videos, we can create the window and layout

    this->setMaximumSize(APP_WIDTH, APP_HEIGHT);
    this->setMinimumSize(APP_WIDTH, APP_HEIGHT);
    this->setWindowTitle("Tomeo");

    QVBoxLayout *layout = new QVBoxLayout();

    QScrollArea *scrollArea = new QScrollArea();
    QWidget *scrollAreaWidgetContents = new QWidget(scrollArea);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollAreaWidgetContents->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    scrollArea->setWidget(scrollAreaWidgetContents);
    scrollAreaWidgetContents->setLayout(layout);
    layout->setContentsMargins(0, 0, 0, 0);

    QLabel *header = new QLabel("My Videos", this);
    header->setStyleSheet("background-color: rgba(0, 0, 0, 0);");
    QFont font = header->font();
    font.setPointSize(18);
    font.setBold(true);
    header->setFont(font);
    header->setAlignment(Qt::AlignHCenter);

    // Add the videos to the layout
    for (int i = 0; i < (int) videos.size(); i++) {

        // Set the video parent to the window as stated in the note in readvideos.cpp
        videos.at(i)->setParent(this);

        // Create the video name label
        QLabel *videoName = new QLabel(videos.at(i)->getVideoName(), this);
        QFont videoNameFont = videoName->font();
        videoNameFont.setPointSize(10);
        videoNameFont.setBold(true);
        videoName->setFont(videoNameFont);

        // Cretae a horizontal layout for the video name so we can add a little space before it
        QHBoxLayout *videoTitleLayout = new QHBoxLayout();
        QSpacerItem *titleSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
        videoTitleLayout->setContentsMargins(0, 0, 0, 0);
        videoTitleLayout->setAlignment(Qt::AlignHCenter);
        videoTitleLayout->addItem(titleSpacer);
        videoTitleLayout->addWidget(videoName);

        QWidget *videoTitleContainer = new QWidget();
        videoTitleContainer->setLayout(videoTitleLayout);

        layout->addWidget(videoTitleContainer);
        layout->addWidget(videos.at(i));

        // Add a spacer between each video
        QSpacerItem *spacer = new QSpacerItem(0, VIDEO_SPACING_HEIGHT, QSizePolicy::Minimum, QSizePolicy::Expanding);
        layout->addItem(spacer);
    }

    // Create the navigation buttons
    navButtons *navButtonsBar = new navButtons(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(header);
    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(navButtonsBar);

    QSpacerItem *bottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);
    mainLayout->addItem(bottomSpacer);

    this->setLayout(mainLayout);

    // Connect the signals and slots
    connect(navButtonsBar, SIGNAL(myProfileButtonClicked()), this, SLOT(myProfileClickedSlot()));
    connect(navButtonsBar, SIGNAL(recordVideoButtonClicked()), this, SLOT(recordVideoClickedSlot()));
    connect(navButtonsBar, SIGNAL(myFriendsButtonClicked()), this, SLOT(myFriendsClickedSlot()));
}

void homeVideos::myProfileClickedSlot()
{
    emit myProfileClicked();
}

void homeVideos::recordVideoClickedSlot()
{
    emit recordVideoClicked();
}

void homeVideos::myFriendsClickedSlot()
{
    emit myFriendsClicked();
}


