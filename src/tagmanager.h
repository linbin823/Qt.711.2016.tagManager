#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QObject>
#include <QUuid>
#include "dbwrap.h"
#include "tag_common.h"
#include "itagmanager.h"

class DriverManager;
class PDBHelper;
//tagManager类：
//  1.保存所有tag信息的实例。
//  2.ui组态时接口：tag参数的新建、删除、修改等操作
//  3.含有driverManager类指针
//  4.单例
class TagManager : public QObject, public ITagManager
{
    Q_OBJECT
public:
    static TagManager * Instance(){
        if(_pSingleton == nullptr){
            _pSingleton = new TagManager();
        }
        return _pSingleton;
    }
    ~TagManager();
    //////////////////start to implement ITagManager
    //ui组态时接口：tag参数的新建、删除、修改等操作
    int newTag(const TagParameters& newTagParameter);
    int deleteTag(const QString& tagName);

    int setTagParameters(const TagParameters& newTagParameter);
    int getTagParameters(const QString& tagName, TagParameters& newTagParameter) const;

    int duplicateTag(const QString& sourceTagName);

    void clearTags();
    qint16 getTagsNum() const;
    QStringList getTagsName() const;
    QList<TagParameters*> getTags() const=0;

    bool isTagExist(const QString& tagName);

    int getRelatedTagList(const QString& driverName, QList<TagParameters*>& tagsUsingDriver);

public slots:

    int stateToConfig(void);
    int stateToRun(void);
    int getState(void);//0-config, 1-run
    //////////////////end of ITagManager implemention

private:

    QList<TagParameters*> _tags;
    static TagManager* _pSingleton;
    DriverManager* _pDriverManager;
    int _state;

    explicit TagManager(QObject *parent = 0);

    bool checkTagName(QString& name);

    QString getTagName (const QString& tagID);
    QString getTagID   (const QString& tagName);

};

#endif // TAGMANAGER_H
