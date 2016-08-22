#ifndef ITAGITEMCOMMON
#define ITAGITEMCOMMON
#include <QObject>

class iTagItemCommon{
    // 读写、修改参数功能
public:
    //被其他任何对象调用，读取信息和数据
    virtual void setName(QString newName)=0;
    virtual int  setType(qint16 newType)=0;
    virtual void setInitialValue(QVariant newValue)=0;

    virtual QString getName() const=0;
    virtual qint16 getType() const=0;
    virtual QVariant getInitialValue() const=0;
    virtual QVariant getValue() const=0;

    //被UI使用，用于写数据
    virtual void setValue(QVariant newValue)=0;
};

#endif // ITAGITEMCOMMON

