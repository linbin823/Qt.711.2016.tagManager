#ifndef ITAG_H
#define ITAG_H

#include "iloadsave.h"

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



enum TagQualityCode: quint16{
    QUALITY_UNDEFINED=0x00,
    QUALITY_GOOD,
    QUALITY_BAD,
    QUALITY_UPDATE_OVERTIME,
    QUALITY_INITIAL,
};

enum TagTypeCode: quint16{
    TYPE_DEFAULT=0x00,
    TYPE_BOOL,
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
    TYPE_DATETIME,
    TYPE_TIME,
    TYPE_DATE,
};

enum TagRWStrategy: quint16{
    RW_READ,
    RW_WRITE,
    RW_READ_WRITE,
};

//tagDriver信息：
//  1、driver名称
//  2、数据地址
//  3、数据类型，枚举
//  4、roll间隔
//  5、write pending bit。
//for tranforming tag parameters
typedef struct _tagDriver{
    QString     driverName;
    QString     address;
    TagTypeCode     dataType;
    int         rollInterv;
    bool        writePending;


    _tagDriver(){
        driverName = QString::null;
        address  = QString::null;
        dataType = TYPE_DEFAULT;
        rollInterv = 10*1000;//10sec
        writePending = false;
    }

    int save(iLoadSaveProcessor* processor){
        processor->saveParameters("driverName",   iLoadSaveProcessor::wrapVal( driverName ) );
        processor->saveParameters("address",      iLoadSaveProcessor::wrapVal( address ) );
        processor->saveParameters("dataType",     iLoadSaveProcessor::wrapVal( (quint16)dataType ) );
        processor->saveParameters("rollInterv",   iLoadSaveProcessor::wrapVal( rollInterv ) );
        processor->saveParameters("writePending", iLoadSaveProcessor::wrapVal( writePending ) );
    }

    int load(iLoadSaveProcessor* processor){
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("driverName"),  driverName );
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("address"),     address );
        quint16 temp;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("dataType"),    temp );
        dataType = temp;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("rollInterv"),  rollInterv );
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("writePending"),writePending );
    }
} TagDriver;

//tagParameters：
//  1、tag的UUID
//  2、tag名称
//  3、tag数据类型，枚举
//  4、tag读写策略，枚举
//  5、tag初始值
//  6、tagDriver相关信息（可以有多个，QList）。

typedef struct _tagParameters{
    QString     tagID;
    QString     tagName;
    TagTypeCode     tagType;
    TagRWStrategy tagRWStrategy;
    QVariant    initialValue;
    QList<TagDriver*> driversInfo;

    _tagParameters(){
        tagID   = QString::null;
        tagName = QString::null;
        tagType = TYPE_DEFAULT;
        tagRWStrategy = RW_READ_WRITE;
        initialValue = QVariant();
        clearDriversInfo();
    }

    ~_tagParameters(){
        clearDriversInfo();
    }

    int save(iLoadSaveProcessor* processor){
        if(!processor) return -1;
        processor->saveParameters("tagID",              iLoadSaveProcessor::wrapVal( tagID ) );
        processor->saveParameters("tagName",            iLoadSaveProcessor::wrapVal( tagName ) );
        processor->saveParameters("tagType",            iLoadSaveProcessor::wrapVal( (quint16)tagType ) );
        processor->saveParameters("tagRWStrategy",      iLoadSaveProcessor::wrapVal( (quint16)tagRWStrategy ) );
        processor->saveParameters("initialValue",       iLoadSaveProcessor::wrapVal( initialValue ) );
        processor->saveParameters("driversInfoLength",  iLoadSaveProcessor::wrapVal( driversInfo.size() ) );
        for(int i=0; i<driversInfo.size(); i++){
            processor->moveToInstance("driversInfo", QString::number(i) );
            driversInfo.at(i)->save( processor );
            processor->moveBackToParent();
        }
        return 0;
    }

    int load(iLoadSaveProcessor* processor){
        if(!processor) return -1;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("tagID"),          tagID );
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("tagName"),        tagName );
        quint16 temp;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("tagType"),        temp );
        tagType = temp;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("tagRWStrategy"),  temp );
        tagRWStrategy = temp;
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("initialValue"),   initialValue );
        int size;
        TagDriver temp;
        clearDriversInfo();
        iLoadSaveProcessor::unwrapVal( processor->loadParameters("driversInfoLength"),size );
        for(int i =0;i < size; i++ ){
            temp = new TagDriver();
            processor->moveToInstance("driversInfo", QString::number(i) );
            temp.load( processor);
            processor->moveBackToParent();
            driversInfo<< temp;
        }
        return 0;
    }

    void clearDriversInfo(void){
        for(int i=0; i<driversInfo.size(); i++){
            delete driversInfo.at(i);
        }
        driversInfo.clear();
    }
} TagParameters;

#endif // ITAG_H
