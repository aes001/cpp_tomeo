#include "readvideos.h"

/*
 * readVideos
 * Reads all videos from a directory and returns a vector of videoPlayers
 * @param path: the path to the directory containing the videos
 * @param parent: the parent widget, defaults to nullptr see note below
 * @return a vector of videoPlayers
 *
 * Note: If you don't pass in a parent you will have to set the parent to each player later with setParent()
 */
std::vector<videoPlayer*> readVideos(std::string path, QWidget *parent){
    std::vector<videoPlayer*> videos = std::vector<videoPlayer*>(); // empty vector

    QDir dir(QString::fromStdString(path));
    QDirIterator it(dir);

    while (it.hasNext()) {
        QString file = it.next();
#if defined(_WIN32)
        if (file.contains(".wmv")){ // windows
#else
        if (file.contains(".mp4") || file.contains("MOV"))  { // mac/linux
#endif
            videoPlayer* v = new videoPlayer(QUrl::fromLocalFile(file), parent);
            videos.push_back(v);
        }
    }
    return videos;
}
