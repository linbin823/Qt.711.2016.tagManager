﻿#include "tagmanager.h"

tagManager::tagManager(QObject *parent):baseDevice(parent){
    connect(&checkerTimer,SIGNAL(timeout()),this,SLOT(checkWireBroken()));
    checkerTimer.setInterval( 2* 1000 );
    checkerTimer.start();


}
tagManager::~tagManager(){
    clearTagItems();
}

/*
 * Item编辑功能。新增TagItem
 * 输入参数：
 * 1、itemID， 可以不指定，此时itemID自动生成。
 * 返回数值：新的tagItem的ID。
 * 功能描述：
 * 1、生成uuid，作为唯一的tagID
 * 2、新建tagItem
 * 3、关联信号和槽
 */
QString tagManager::insertTagItem(QString& newitemID ){
    QString itemID;
    if(newitemID.isNull()){
        itemID= QUuid::createUuid().toString();
    }
    else{
        itemID= newitemID;
    }
    tagItem* newItem = new tagItem(this);
    connect(newItem,SIGNAL(msgTagItemChanged(tagItem*)),this,SLOT(tagItemChanged(tagItem*)) );
    //qDebug()<<"tagManager::insertTagItem"<<"step1";
    tagItems.insert(itemID, newItem);
    //qDebug()<<"tagManager::insertTagItem"<<"step2";
    newItem->initial();
    return itemID;
}
/*
 * Item编辑功能。复制TagItem
 * 输入参数：
 * 1、sourceItemID，原有的的tagItem的ID。
 * 2、newitemID，新的tagItem的ID。可以不指定，此时itemID自动生成。
 * 返回数值：新的tagItem的ID。复制失败返回0。
 * 功能描述：
 * 1、查找原有的tagItem*
 * 2、复制一个新的tagItem*
 * 3、插入
 */
QString tagManager::duplicateTagItem(QString& sourceItemID){
    tagItem* sourceTagItem = getTagItem(sourceItemID);
    if(sourceTagItem == 0){
        return QString::null;
    }
    QString targetTagItemID = insertTagItem();
    tagItem* targetTagItem = getTagItem(targetTagItemID);
    targetTagItem->setInitialValue( sourceTagItem->getInitialValue() );
    targetTagItem->setType( sourceTagItem->getType() );
    targetTagItem->updateData( sourceTagItem->getValue(), tagItem::QUALITY_GOOD );
    QString targetTagItemName = targetTagItem->getName() + QString("_new");
    targetTagItem->setName( targetTagItemName );
    return targetTagItemID;
}

/*
 * Item编辑功能。删除TagItem
 * 输入参数：
 * 1、itemID:要删除的tagItem的ID。
 * 返回数值：无。
 * 功能描述：
 * 1、查找要删除的tagItem*
 * 2、从tagItems列表中删除
 */
void tagManager::deleteTagItem( QString& itemID){
    tagItem* sourceTagItem = getTagItem(itemID);
    //qDebug()<<"tagManager::deleteTagItem"<<sourceTagItem->getName();
    if(sourceTagItem == 0){
        return;
    }
    disconnect(sourceTagItem,SIGNAL(msgTagItemChanged(tagItem*)),this,SLOT(tagItemChanged(tagItem*)));
    emit msgTagItemRemoved(itemID);
    tagItems.remove(itemID);
}

/*
 * Item编辑功能。删除所有TagItem
 * 输入参数：无。
 * 返回数值：无。
 * 功能描述：
 * 1、删除所有TagItem
 * 2、清空tagItems列表
 */
void tagManager::clearTagItems(){
    QHashIterator<QString,tagItem*> it(tagItems);
    if(tagItems.isEmpty()) return;
    it.toFront();
    do{
        it.next();
        QString key = it.key();
        deleteTagItem( key );
    }while(it.hasNext());
}
/*
 * Item编辑功能。查找tagItem*
 * 输入参数：
 * 1、tagItem的名字
 * 2、bool代表是否成功找到
 * 返回数值：对应的tagItem*
 * 功能描述：
 * 1、查找tagItem*
 */
tagItem* tagManager::getTagItem(QString& itemID,bool* ok) const{
    QHash<QString,tagItem*>::const_iterator it = tagItems.find(itemID);
    if(it == tagItems.end() ){//找不到
        if(ok != 0) *ok = false;
        return 0;
    }
    if(ok != 0) *ok = true;
    return it.value();
}

/*
 * Item编辑功能。查找tagItemID
 * 输入参数：
 * 1、tagItem*
 * 2、bool代表是否成功找到
 * 返回数值：对应的tagItemID
 * 功能描述：
 * 1、查找tagItemID
 */
QString tagManager::getTagItemID(tagItem*  tag,bool* ok) const{
    QHashIterator<QString,tagItem*> it(tagItems);
    if(tagItems.isEmpty()) return QString::null;
    //qDebug()<<"tagManager::getTagItemID"<<tag;
    it.toFront();
    while(it.hasNext()){
        it.next();
        //qDebug()<<"tagManager::getTagItemID"<<it.value()<<it.key();
        if(it.value() == tag){
            if(ok != 0) *ok = true;
            //qDebug()<<"tagManager::getTagItemID"<<it.key();
            return it.key();
        }
    }
    if(ok != 0) *ok = false;
    return QString::null;
}
/*
 * Item编辑功能。获取TagItem数量
 * 输入参数：无。
 * 返回数值：TagItem数量
 * 功能描述：
 * 1、获取TagItem数量
 */
qint16 tagManager::getTagItemsNum() const{
    return tagItems.size();
}

/*
 * Item编辑功能。获取TagItemID和TagItemName的Map
 * 输入参数：无。
 * 返回数值：TagItemID和TagItemName的Map
 * 功能描述：
 * 1、获取TagItemID和TagItemName的Map
 */
QMap<QString,QString> tagManager::getTagItemsIDandName() const{
    QMap<QString,QString> tagItemsName;
    QHashIterator<QString,tagItem*> it(tagItems);
    if(tagItems.isEmpty()) return tagItemsName;
    it.toFront();
    do{
        it.next();
        tagItemsName.insert(it.key(), it.value()->getName());
    }while(it.hasNext());
    return tagItemsName;
}

/*
 * Item编辑功能。获取TagItemID的List
 * 输入参数：无。
 * 返回数值：TagItemID的List
 * 功能描述：
 * 1、获取TagItemID的List
 */
QStringList tagManager::getTagItemsID() const{
    QStringList ids;
    QHashIterator<QString,tagItem*> it(tagItems);
    if(tagItems.isEmpty()) return ids;
    it.toFront();
    do{
        it.next();
        ids<<it.key();
    }while(it.hasNext());
    return ids;
}
/*
 * Item编辑功能。判断tagItem是否存在
 * 输入参数：tagID
 * 返回数值：bool
 * 功能描述：
 * 1、通过tagID判断tagItem是否存在
 */
bool tagManager::isTagItemExist(QString& itemID){
    bool ok;
    getTagItem(itemID,&ok);
    return ok;
}
/*
 * Item编辑功能。判断tagItem是否存在
 * 输入参数：tagItem*
 * 返回数值：bool
 * 功能描述：
 * 1、通过tagItem*判断tagItem是否存在
 */
bool tagManager::isTagItemExist(tagItem*  tag){
    bool ok;
    getTagItemID(tag,&ok);
    return ok;
}

/*
 * Item读取保存功能。保存
 * 输入参数：读取保存处理器。
 * 返回数值：成功返回0
 * 功能描述：
 * 1、保存所有的属性和调用子对象的保存函数
 */
int tagManager::save(iLoadSaveProcessor* processor){


    baseDevice::save(processor);
    return 0;
}

/*
 * Item读取保存功能。读取
 * 输入参数：读取保存处理器。
 * 返回数值：TagItemID和TagItemName的Map
 * 功能描述：
 * 1、读取所有属性和调用子对象的读取函数
 */
int tagManager::load(iLoadSaveProcessor* processor){


    baseDevice::load(processor);
    return 0;
}

/*
 * Item检查功能。检查重名
 * 输入参数：无
 * 返回数值：无
 * 功能描述：
 * 1、名称有修改后，调用本函数。
 * 2、检查所有TagItem有没有重名。
 * 3、有重名则发送错误信号
 */
void tagManager::checkDuplicatedName(){

}

/*
 * Item检查功能。检查断线
 * 输入参数：检查断线
 * 返回数值：无
 * 功能描述：
 * 1、定时调用本函数。
 * 2、检查断线
 */
void tagManager::checkWireBroken(){
    if(tagItems.isEmpty()) return;
    QHashIterator<QString,tagItem*> it(tagItems);
    it.toFront();
    //qDebug()<<"tagManager::checkWireBroken"<<tagItems.size();
    do{
        it.next();
        //qDebug()<<"tagManager::checkWireBroken"<<it.value()->getName();
        it.value()->selfCheck();
    }while(it.hasNext());
}
/*
 * private槽函数，负责信号转发
 * 输入参数：tagItem*
 * 返回数值：无
 * 功能描述：
 * 1、信号的集中和转发
 */
void tagManager::tagItemChanged(tagItem* item){
    QString ID = getTagItemID( item );
    emit msgTagItemChanged(ID);
}
