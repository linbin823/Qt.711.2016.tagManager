#include "tagitem.h"

tagItem::tagItem(QObject *parent):QObject(parent){
    name = QString::fromLocal8Bit("newTag");
    rollInterv = 1000 * 10;//10s
    initial();
}

tagItem::~tagItem(){

}
/*
 * Item初始化。被tagManager调用
 * 输入参数：无
 * 返回数值：无
 * 功能描述：
 * 1、初始化value和质量
 */
void tagItem::initial(){
    value = initialValue;
    quality = QUALITY_INITIAL;
    lastUpdate.start();
    //qDebug()<<"tagItem::initial"<<this;
    emit msgTagItemChanged(this);
    emit msgTagItemValueChanged(this);
}

/*
 * 更新tagItem值。被driver调用
 * 输入参数：
 * 1、数值
 * 返回数值：无
 * 功能描述：
 * 1、更新数值和质量代码
 */
void tagItem::updateData(QVariant& newData, qint16 newQuality){
    if(!writePending){
        if(value!=newData){
            value = newData;
            emit msgTagItemValueChanged(this);
        }
        if(quality!= newQuality){
            quality = newQuality;
            emit msgTagItemChanged(this);
        }
    }
    lastUpdate.start();
}

/*
 * 更新rollInterv值。被driver调用
 * 输入参数：
 * 1、数值
 * 返回数值：无
 * 功能描述：
 * 1、更新rollInterv
 */
void tagItem::setRollInterv(qint32 newRollInterv){
    rollInterv = newRollInterv;
}
/*
 * 复位写等待标志。被driver调用
 * 输入参数：无
 * 返回数值：无
 * 功能描述：
 * 1、复位写等待标志
 */
void tagItem::resetWritePending(){
    writePending = false;
}

/*
 * 设置Item名称。被tagGroup或UI调用
 * 输入参数：
 * 1、新名称
 * 返回数值：无
 * 功能描述：无
 */
void tagItem::setName(QString newName){
    name = newName;
    emit msgTagItemNameChanged(this);
    emit msgTagItemChanged(this);
}
/*
 * 设置Item类型。被tagGroup或UI调用
 * 输入参数：
 * 1、新类型
 * 返回数值：设置无效返回-1，正常返回0
 * 功能描述：无
 */
int tagItem::setType(qint16 newType){
    if(newType < 0x00 || newType >=TYPE_END)
        return -1;
    type = newType;
    emit msgTagItemChanged(this);
    return 0;
}
/*
 * 设置Item初始值。被tagGroup或UI调用
 * 输入参数：
 * 1、新初始化值
 * 返回数值：无
 * 功能描述：无
 */
void tagItem::setInitialValue(QVariant newValue){
    if(newValue.isValid()){
        initialValue = newValue;
        emit msgTagItemChanged(this);
    }

}

/*
 * Item自检。被tagManager调用
 * 输入参数：无
 * 返回数值：无
 * 功能描述：
 * 1、检查是否超时
 */
void tagItem::selfCheck(){
    //qDebug()<<"tagItem::selfCheck"<<"step1";
    if(quality == QUALITY_GOOD){
        if(lastUpdate.elapsed() >= rollInterv){
            //qDebug()<<"tagItem::selfCheck"<<"step2";
            quality = QUALITY_UPDATE_OVERTIME;
            emit msgTagItemChanged(this);
        }
    }
}

/*
 * 读取tag名称。被tagManager或UI调用
 * 输入参数：无
 * 返回数值：tag名称
 * 功能描述：无
 */
QString tagItem::getName() const{
    return name;
}
/*
 * 读取tag类型。被tagManager或UI调用
 * 输入参数：无
 * 返回数值：tag类型
 * 功能描述：无
 */
qint16 tagItem::getType() const{
    return type;
}
/*
 * 读取tag初始值。被tagManager或UI调用
 * 输入参数：无
 * 返回数值：tag初始值
 * 功能描述：无
 */
QVariant tagItem::getInitialValue() const{
    return initialValue;
}

/*
 * 读取tag值。被tagManager或UI调用
 * 输入参数：无
 * 返回数值：tag值
 * 功能描述：无
 */
QVariant tagItem::getValue() const{
    return value;
}

/*
 * 写tag值。被UI调用
 * 输入参数：无
 * 返回数值：无
 * 功能描述：无
 */
void tagItem::setValue(QVariant newValue){
    if(newValue.isValid()){
        value = newValue;
        writePending = true;
        emit msgTagItemValueChanged(this);
    }
}
/*
 * 保存。被manager调用
 * 输入参数：读取保存处理器指针
 * 返回数值：成功返回0
 * 功能描述：
 * 1、保存所有参数
 */
int tagItem::save(iLoadSaveProcessor* processor){
    processor->saveParameters( QString("name"),name);

    processor->saveParameters( QString("type"),QString::number(type));
    processor->saveParameters( QString("rollInterv"),QString::number(rollInterv));
    processor->saveParameters( QString("quality"),QString::number(quality));

    processor->saveParameters( QString("initialValue"),initialValue.toString());
    processor->saveParameters( QString("value"),value.toString());

    if(writePending){
        processor->saveParameters( QString("writePending"),QString("true"));
    }
    else processor->saveParameters( QString("writePending"),QString("false"));
    return 0;
}
/*
 * 读取。被manager调用
 * 输入参数：读取保存处理器指针
 * 返回数值：成功返回0
 * 功能描述：
 * 1、读取所有参数
 */
int tagItem::load(iLoadSaveProcessor* processor){
    QString res,res1;
    bool ok;
    processor->loadParameters( QString("name") , &res );
    setName(res);
    processor->loadParameters( QString("type") , &res );
    setType(res.toUInt(&ok,10));
    processor->loadParameters( QString("rollInterv") , &res );
    setRollInterv(res.toUInt(&ok,10));
    processor->loadParameters( QString("initialValue") , &res );
    setInitialValue(QVariant(res));
    processor->loadParameters( QString("writePending") , &res );
    if(value == QString("true")){
        writePending = true;
    }
    else writePending = false;

    processor->loadParameters( QString("quality") , &res );
    processor->loadParameters( QString("value") , &res1 );
    updateData(QVariant(res1), res.toUInt(&ok,10) );

    return 0;
}
