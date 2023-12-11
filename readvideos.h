#ifndef READVIDEOS_H
#define READVIDEOS_H
#include <vector>
// #include "constants.h"
#include "videoplayer.h"
#include <QDirIterator>

std::vector<videoPlayer*> readVideos(std::string path, QWidget *parent = nullptr);

#endif // READVIDEOS_H
