QT       += core network
include(..\..\..\Qt.711.2016.common\lib\common\common.pri)
include(..\..\..\Qt.711.2016.saveLoadProcessor\lib\loadSave\saveLoadProcessor.pri)

SOURCES += \
    $$PWD/tagitem.cpp \
    $$PWD/tagmanager.cpp

HEADERS  += \ 
    $$PWD/itagitemupdate.h \
    $$PWD/itagitemcommon.h \
    $$PWD/itagitemselfcheck.h \
    $$PWD/tagitem.h \
    $$PWD/tagmanager.h \
    $$PWD/itagmanageroperateitem.h \
    $$PWD/itagmanagercheckitem.h

INCLUDEPATH += $$PWD\

DISTFILES += \
    $$PWD\../../HISTORY.txt \
    $$PWD\../../README.txt
