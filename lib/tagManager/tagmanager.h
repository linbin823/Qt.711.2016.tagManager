#ifndef TAGMANAGER_H
#define TAGMANAGER_H

#include <QHash>
#include <QHashIterator>
#include <QMap>
#include <QMapIterator>
#include <QTimer>
#include <QUuid>

#include "tagitem.h"
#include "iloadsave.h"
#include "basedevice.h"
#include "itagmanageroperateitem.h"
#include "itagmanagercheckitem.h"

class tagManager:public baseDevice, public iTagManagerOperateItem, public iTagManagerCheckItem
{
    Q_OBJECT
public:
    tagManager(QObject *parent = 0);
    ~tagManager();

    enum state: quint64{
        stateOK            = 0x0000000000000001ULL,      //就绪
    };
    virtual QString getStateString(int lang = 0 ) const{
         return QString::fromLocal8Bit("tagManager就绪");
     };
    enum errorType : quint64 {
    };
protected:
    virtual QString getErrorString(quint64 errorCode, int lang =0 ) const{
        return QString::fromLocal8Bit("无错误");
    }

public:
    virtual QString insertTagItem(QString& newitemID=QString() );
    virtual QString duplicateTagItem(QString& sourceItemID);
    virtual void deleteTagItem(QString& itemID);
    virtual void clearTagItems();

    virtual tagItem* getTagItem(QString& itemID,bool* ok=0) const;
    virtual QString getTagItemID(tagItem*  tag,bool* ok=0) const;
    virtual qint16 getTagItemsNum() const;
    virtual QMap<QString,QString> getTagItemsIDandName() const;
    virtual QStringList getTagItemsID() const;

    virtual bool isTagItemExist(QString& itemID);
    virtual bool isTagItemExist(tagItem*  tag);

    virtual int save(iLoadSaveProcessor* processor);
    virtual int load(iLoadSaveProcessor* processor);
signals:

    void msgTagItemChanged(QString itemID);
    void msgTagValueChanged(QString itemID);
    void msgTagItemRemoved(QString itemID);
private:
    QHash<QString,tagItem*> tagItems;
    QTimer checkerTimer;

    virtual void checkDuplicatedName();

public slots:
    void tagItemChanged(tagItem* item);
    virtual void checkWireBroken();
};

#endif // TAGMANAGER_H
