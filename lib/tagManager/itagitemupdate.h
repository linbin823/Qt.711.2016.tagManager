#ifndef ITAGITEMUPDATE
#define ITAGITEMUPDATE
#include <QObject>

class iTagItemUpdate{
   // 数据更新功能
public:
    virtual void updateData(QVariant& newData, qint16 newQuality)=0;
    virtual void setRollInterv(qint32 newRollInterv)=0;
    virtual void resetWritePending()=0;
};

#endif // ITAGITEMUPDATE

