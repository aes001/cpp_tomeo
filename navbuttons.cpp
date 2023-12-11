#include "navbuttons.h"

navButtons::navButtons(QUrl iconURL, int width_size_ratio, QWidget *parent): QLabel(parent), iconURL(iconURL)
{
    QPixmap icon(iconURL.toLocalFile());
    icon = icon.scaled(APP_WIDTH/width_size_ratio, APP_WIDTH/width_size_ratio, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setPixmap(icon);
    this->setAlignment(Qt::AlignCenter);
    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

}
