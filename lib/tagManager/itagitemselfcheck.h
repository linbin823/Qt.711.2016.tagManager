#ifndef ITAGITEMSELFCHECK
#define ITAGITEMSELFCHECK
#include <QObject>

class iTagItemSelfCheck{
    //自检查功能
    //被manager调用，用以自查和初始化。
public:
    virtual void selfCheck()=0;
    virtual void initial()=0;
};
#endif // ITAGITEMSELFCHECK

