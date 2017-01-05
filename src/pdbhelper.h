#ifndef PDBHELPER_H
#define PDBHELPER_H

#include <QObject>
#include <QSqlDriver>
#include "tag_common.h"
#include "ipdbhelper.h"
//PDBHelper类：
//  1.运行时接口：封装tag数值的写操作（含数据驱动写、UI写两种），保存至本地DB文件的接口。
//  2.切换到运行时，拷贝pdb至内存的接口。
//  3.运行时接口：发送valueChanged信号、qualityChanged信号至UI。
//  4.运行时接口：发送writePending信号至driverManager，置位write pending bit
//  5.单例
class PDBHelper : public QObject , public IPDBHelper
{
    Q_OBJECT
public:
    static PDBHelper * Instance(){
        if(_pSingleton == nullptr){
            _pSingleton = new PDBHelper();
        }
        return _pSingleton;
    }
    ~PDBHelper();

    //////////////////start to implement IPDBHelper
    //set one tag's value, for UI objects
    //write pending will set.
    virtual int setValue(const QString& tagName, const QVariant& newValue)=0;
    //update one tag's value, for driver
    virtual void updateData(const QString& tagName, const QVariant& newValue, TagQuality newQuality)=0;

public slots:

    int stateToConfig(void);
    int stateToRun(void);
    int getState(void);//0-config, 1-run
    //////////////////end of ITagManager implemention

private:
    explicit PDBHelper(QObject *parent = 0);
    static PDBHelper* _pSingleton;

    QSqlDriver * _pdb;

    int sqliteDBMemFile(QString filename, bool save );

signals:
    void tagValueChanged(const QString& tagName, const QVariant& value);
    void tagQualityChanged(const QString& tagName, const TagQualityCode& newQuality);

public slots:

};

#endif // PDBHELPER_H
