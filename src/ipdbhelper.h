#ifndef IPDBHELPER_H
#define IPDBHELPER_H


//PDBHelper类：
//  1.运行时接口：封装tag数值的写操作（含数据驱动写、UI写两种），保存至本地DB文件的接口。
//  2.切换到运行时，拷贝pdb至内存的接口。
//  3.运行时接口：发送valueChanged信号、qualityChanged信号至UI。
//  4.运行时接口：发送writePending信号至driverManager，置位write pending bit
//  5.单例

class IPDBHelper{
public:
    IPDBHelper(void){}
    virtual ~IPDBHelper(){}

    //ignore read interface
    //virtual QVariant& getValue(const QString& tagName ) const=0;
    //virtual qualityCode& getQualityCode(const QString& tagName ) const=0;

    //set one tag's value, for UI objects
    //write pending will set.
    virtual int setValue(const QString& tagName, const QVariant& newValue)=0;
    //update one tag's value, for driver
    virtual void updateData(const QString& tagName, const QVariant& newValue, TagQuality newQuality)=0;

    int stateToConfig(void);
    int stateToRun(void);
    int getState(void);//0-config, 1-run
};

#endif // IPDBHELPER_H
