QT       += core network sql

include(../lib/loadSaveProcessor/src/loadsaveProcessor.pri)
include(../lib/DBWrap/src/dbwrap.pri)

SOURCES += \
    $$PWD/tagmanager.cpp \
    $$PWD/pdbhelper.cpp \
    $$[QT_INSTALL_PREFIX]/../Src/qtbase/src/3rdparty/sqlite/sqlite3.c

HEADERS  += \
    $$PWD/tagmanager.h \
    $$PWD/itagmanager.h \
    $$PWD/ipdbhelper.h \
    $$PWD/pdbhelper.h \
    $$PWD/tag_common.h

INCLUDEPATH += $$PWD \
    $$[QT_INSTALL_PREFIX]/../Src/qtbase/src/3rdparty/sqlite

DISTFILES += \
    $$PWD/../HISTORY.txt \
    $$PWD/../README.txt
