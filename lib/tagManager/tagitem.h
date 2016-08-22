#ifndef TAGITEM_H
#define TAGITEM_H
#include <QVariant>
#include <QTime>
#include <QMap>
#include "iloadsave.h"
#include "itagitemcommon.h"
#include "itagitemupdate.h"
#include "itagitemselfcheck.h"

//数据点
//OPC的数据质量代码（做参考）：
//        MASK_QUALITY            =	0xc0,
//        MASK_STATUS             =	0xfc,
//        MASK_LIMIT              =	0x3,
//        QUALITY_BAD             =	0x00,               //值为坏的，没有标明原因
//        QUALITY_UNCERTAIN       =	0x40,               //没有指定原因说明值为什么不确定
//        QUALITY_GOOD            =	0xc0,               //值是好的
//        QUALITY_CONFIG_ERROR	=	0x04,               //服务器特定的配置问题
//        QUALITY_NOT_CONNECTED	=	0x08,               //输入没有可用的连接
//        QUALITY_DEVICE_FAILURE	=	0x0c,               //设备故障
//        QUALITY_SENSOR_FAILURE	=	0x10,               //传感器故障
//        QUALITY_LAST_KNOWN  	=	0x14,               //通讯失败。最后的值是可用的
//        QUALITY_COMM_FAILURE	=	0x18,               //通讯失败，最后的值不可用
//        QUALITY_OUT_OF_SERVICE	=	0x1c,               //块脱离扫描或者被锁
//        QUALITY_WAITING_FOR_INITIAL_DATA	=	0x20,   //等待初始化数据
//        QUALITY_LAST_USABLE     =	0x44,               //最后的可用值
//        QUALITY_SENSOR_CAL  	=	0x50,               //感器达到了它的一个限值或者超过了它的量程
//        QUALITY_EGU_EXCEEDED	=	0x54,               //返回值越限
//        QUALITY_SUB_NORMAL      =	0x58,               //值有几个源，并且可用的源少于规定的品质好的源
//        QUALITY_LOCAL_OVERRIDE	=	0xd8,               //值被覆盖。典型意思为输入失去连接和手动被强制
//        LIMIT_OK	=	0,                              //限制，ok
//        LIMIT_LOW	=	0x1,                            //限制，超下限
//        LIMIT_HIGH	=	0x2,                            //限制，超上限
//        LIMIT_CONST	=	0x3,                            //限制，常数


class tagItem : public QObject ,public iLoadSave, public iTagItemCommon, public iTagItemUpdate, public iTagItemSelfCheck
{
    Q_OBJECT
public:
    tagItem(QObject *parent = 0);
    ~tagItem();

    enum qualityCode: qint16{

        QUALITY_GOOD  =0x00,
        QUALITY_BAD,
        QUALITY_UPDATE_OVERTIME,
        QUALITY_INITIAL,
    };
    enum typeCode: qint16{
        TYPE_BOOL  =0x00,
        TYPE_BYTE,
        TYPE_WORD,
        TYPE_INT16,
        TYPE_INT32,
        TYPE_INT64,
        TYPE_UINT16,
        TYPE_UINT32,
        TYPE_UINT64,
        TYPE_FLOAT,
        TYPE_DOUBLE,
        TYPE_STRING,
        TYPE_END,
    };

private:
    QString name;
    qint16 type;
    QVariant initialValue;
    qint32 rollInterv;

    qint16 quality;
    QVariant value;
    QTime lastUpdate;

    bool writePending;//有新的值准备向设备写入

public:
    //被driver调用，用以更新值。
    virtual void updateData(QVariant& newData, qint16 newQuality);
    virtual void setRollInterv(qint32 newRollInterv);
    virtual void resetWritePending();

    //被manager调用，用以自查和初始化。
    virtual void selfCheck();
    virtual void initial();

    //被UI调用，用以修改或新建tagItem
    virtual void setName(QString newName);
    virtual int  setType(qint16 newType);
    virtual void setInitialValue(QVariant newValue);
    //被其他任何对象调用，读取信息和数据
    virtual QString getName() const;
    virtual qint16 getType() const;
    virtual QVariant getInitialValue() const;
    virtual QVariant getValue() const;

    virtual int save(iLoadSaveProcessor* processor);
    virtual int load(iLoadSaveProcessor* processor);

public slots:
    //被UI使用，用于写数据
    virtual void setValue(QVariant newValue);

signals:
    void msgTagItemNameChanged(tagItem* item);
    void msgTagItemChanged(tagItem* item);
    void msgTagItemValueChanged(tagItem* item);
};

#endif // TMTAG_H
