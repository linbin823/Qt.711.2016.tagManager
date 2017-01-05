#ifndef ITAGMANAGER
#define ITAGMANAGER
#include <QObject>
#include "tag_common.h"

//tagManager类：
//  1.保存所有tag信息的实例。
//  2.ui组态时接口：tag参数的新建、删除、修改等操作
//  3.含有driverManager类指针
//  4.单例

class ITagManager{
public:
    ITagManager(void){}
    virtual ~ITagManager(){}

    //ui组态时接口：tag参数的新建、删除、修改等操作
    virtual int newTag(const TagParameters& newTagParameter)=0;
    virtual int deleteTag(const QString& tagName)=0;

    virtual int setTagParameters(const TagParameters& newTagParameter)=0;
    virtual int getTagParameters(const QString& tagName, TagParameters& newTagParameter) const=0;

    virtual int duplicateTag(const QString& sourceTagName)=0;

    virtual void clearTags()=0;
    virtual qint16 getTagsNum() const=0;
    virtual QStringList getTagsName() const=0;
    virtual QList<TagParameters*> getTags() const=0;

    virtual bool isTagExist(const QString& tagName)=0;

    virtual int getRelatedTagList(const QString& driverName, QList<TagParameters*>& tagsUsingDriver)=0;

    int stateToConfig(void);
    int stateToRun(void);
    int getState(void);//0-config, 1-run
};


//driverManager类：
//  1.含QVector<driver*>，保存driver的实例。
//  2.ui组态时接口：新建、删除、修改各种类型driver。
//  3.ui组态时接口：封装修改tagDriver信息，调用对应driver的verify函数
//  4.含有tagManager类。
//  5.切换到运行时，从tagManager类获取每个driver对应的tagParameters列表，转发给每个driver
//  6.运行时接口：接收pDBHelper发送的writePending signal，置位对应driver的write pending bit
//  7.单例
class IDriverManager{

    virtual void setRollInterv(const QString& tagName, qint32 newRollInterv)=0;
    virtual void resetWritePending(const QString& tagName)=0;

    //ui组态时接口：新建、删除、修改各种类型driver。
    virtual int newDriver(const QString& driverName,const QString& driverType)=0;
    virtual int deleteTag(const QString& tagName)=0;

    virtual int setDriverParameters()=0;
    virtual QStringList getDriversName()=0;
    virtual QStringList getSupportDriversType()=0;

    int stateToConfig(void);
    int stateToRun(void);
    int getState(void);//0-config, 1-run

};


#endif // ITAGMANAGER
