#ifndef ITAGMANAGEROPERATEITEM
#define ITAGMANAGEROPERATEITEM
#include <QObject>
class tagItem;

class iTagManagerOperateItem{
    //标签项操作
public:
    virtual QString insertTagItem(QString& itemID=QString() )=0;
    virtual QString duplicateTagItem(QString& sourceItemID)=0;
    virtual void deleteTagItem(QString& itemID)=0;
    virtual void clearTagItems()=0;

    virtual tagItem* getTagItem(QString& itemID,bool* ok=0) const=0;
    virtual QString getTagItemID(tagItem*  tag,bool* ok=0) const=0;
    virtual qint16 getTagItemsNum() const=0;
    virtual QMap<QString,QString> getTagItemsIDandName() const=0;
    virtual QStringList getTagItemsID() const=0;

    virtual bool isTagItemExist(QString& itemID)=0;
    virtual bool isTagItemExist(tagItem*  tag)=0;

};

#endif // ITAGMANAGEROPERATEITEM
