﻿#ifndef ITAGMANAGERCHECKITEM
#define ITAGMANAGERCHECKITEM
#include <QObject>
class tagItem;

class iTagManagerCheckItem{
    //标签项检查
public:
    virtual void checkDuplicatedName()=0;
    virtual void checkWireBroken()=0;


};
#endif // ITAGMANAGERCHECKITEM

