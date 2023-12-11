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

    // Check if the directory exists
    QFileInfo checkFile(QString::fromStdString(path));
    if (!(checkFile.exists() && checkFile.isDir())) {
        DEBUG_MSG("Directory does not exist: " << QString::fromStdString(path))
        return videos;
    } else {
        DEBUG_MSG("Directory found: " << checkFile.path())
    }

    QDir dir = QDir();

    // Check if the path is relative or absolute
    if(checkFile.isRelative()){
        DEBUG_MSG("Path is relative. Using canonical path: " << checkFile.canonicalFilePath() << " instead of " << QString::fromStdString(path) << ".")
        dir = QDir(checkFile.canonicalFilePath()); //Have to do this for some reason or it won't work with relative paths
    } else {
        DEBUG_MSG("Path is absolute. Using path: " << QString::fromStdString(path))
        dir = QDir(QString::fromStdString(path)); // We just use the path as is if it's already absolute
    }

    // Iterate through the directory and add all videos to the vector
    QDirIterator it(dir);
    while (it.hasNext()) {
        QString file = it.next();
#if defined(_WIN32)
        if (file.contains(".wmv")){ // windows
            DEBUG_MSG("Found video: " << it.fileName())

#else
        if (file.contains(".mp4") || file.contains("MOV"))  { // mac/linux
#endif
            videoPlayer* v = new videoPlayer(QUrl::fromLocalFile(file), parent);
            videos.push_back(v);
        }
    }
    return videos;
}
