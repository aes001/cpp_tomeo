#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QDebug>

// Do not change
// Some design mishap and miscommunication has made changing these constants
// result in a broken UI. Please do not change these constants.
#define APP_WIDTH 400 // Old size: 878/2
#define APP_HEIGHT 710 // Old size: 1792

#define VIDEO_SPACING_HEIGHT 40

// Debug Macro
// Change DEBUG_ENABLE to true to enable debug messages
#define DEBUG_ENABLE true

#ifdef DEBUG_ENABLE
#define DEBUG_MSG(str) \
    if(DEBUG_ENABLE){ \
        qDebug() << str; \
    } else {}
#else
#define DEBUG_MSG(str) do {} while (0);
#endif

#endif // CONSTANTS_H
