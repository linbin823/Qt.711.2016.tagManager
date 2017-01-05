#include "tagmanager.h"

TagManager::TagManager(QObject *parent) : QObject(parent){
    _state = 0;
    clearTags();
}

TagManager::~TagManager(){
}


//////////////////////////////////////////////////////////////////////////start to implement ITagManager
//ui组态时接口：tag参数的新建、删除、修改等操作
/***********************************************
* newTag
* insert a new tag into the table
* input:   TagParameters& newTagParameters
* return:  0  success
*          -1 failed
* tags' name should not conflit with each other
* tagID is generated just in this function.
**********************************************/
int TagManager::newTag(const TagParameters& newTagParameter){
    int ret =-1;
    if(_state !=0 ){
        return ret;
    }
    if( newTagParameter.tagName.isEmpty() ){
        return ret;
    }

    TagParameters* newone = new TagParameters();
    newone->tagID = QUuid::createUuid().toString();//create udid
    _tags<<newone;

    ret = setTagParameters( newone );
    return ret;
}
/***********************************************
 * deleteTag
 * delete a tag from the table
 * input:   const QString& tagName
 * return:  0  success
 *          -1 failed
 **********************************************/
int TagManager::deleteTag(const QString& tagName){
    int ret =-1;
    if(_state !=0 ){
        return ret;
    }
    if( tagName.isEmpty() ){
        return ret;
    }
    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagName == tagName){
            delete _tags.at(i);
            _tags.removeAt(i);
            ret =0;
            return ret;
        }
    }
    return ret;
}

/***********************************************
 * setTagParameters
 * set a tag's parameters
 * input:   const TagParameters& newTagParameters
 * return:  0  success
 *          -1 failed
 **********************************************/
int TagManager::setTagParameters(const TagParameters& newTagParameters){
    int ret = -1;
    if(_state !=0 ){
        return ret;
    }
    QString _tagID =    newTagParameters.tagID;
    QString _tagName =  newTagParameters.tagName;
    if( _tagName.isEmpty() || _tagID.isEmpty() ){
        return ret;
    }
    checkTagName( _tagName );//change the name if has duplication.

    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagID == _tagID){
            memcpy(_tags.at(i), &newTagParameters, sizeof(TagParameters));
            ret =0;
            return ret;
        }
    }
    return ret;
}

/***********************************************
 * getTagParameters
 * get a tag's parameters
 * input:
 * const QString& tagName
 * output:
 * const TagParameters& tagParameters
 * return:  0  success
 *          -1 failed
 **********************************************/
int TagManager::getTagParameters(const QString& tagName, TagParameters& newTagParameter) const{
    int ret = -1;
    if( tagName.isEmpty() ){
        return ret;
    }
    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagName == tagName){
            memcpy(&newTagParameter,_tags.at(i), sizeof(TagParameters));
            ret =0;
            return ret;
        }
    }
    return ret;
}

/***********************************************
 * copy tag.
 * input:   const QString& sourceTagName
 * return:  0  success
 *          -1 failed
 **********************************************/
int TagManager::duplicateTag(const QString& sourceTagName){
    int ret = -1;
    if(_state !=0 ){
        return ret;
    }
    if( sourceTagName.isEmpty() ){
        return ret;
    }

    TagParameters newTagParameter;
    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagName == sourceTagName){
            memcpy(&newTagParameter,_tags.at(i), sizeof(TagParameters));
            ret = newTag(newTagParameter);
            return ret;
        }
    }
    return ret;
}
/***********************************************
 * copy tag.
 * input:   none
 * return:  none
 **********************************************/
void TagManager::clearTags(){
    if(_state !=0 ){
        return;
    }
    for(int i=0;i<_tags.size();i++){
        delete _tags.at(i);
    }
    _tags.clear();
}

/***********************************************
 * get _tags number.
 * input:   none
 * return:  _tags count
 **********************************************/
qint16 TagManager::getTagsNum() const{
    return _tags.size();
}

/***********************************************
 * get _tags name.
 * input:   none
 * return:  list of _tags name
 **********************************************/
QStringList TagManager::getTagsName() const{
    QStringList ret;
    for(int i=0; i<_tags.size(); i++){
        ret << _tags.at(i)->tagName;
    }
    return ret;
}

/***********************************************
 * get _tags list.
 * input:   none
 * return:  list of _tags
 **********************************************/
QList<TagParameters*> TagManager::getTags() const{
    return _tags;
}
/***********************************************
 * isTagExist.
 * input:   const QString& tagName
 * return:  false not exist
 *          true exist
 **********************************************/
bool TagManager::isTagExist(const QString& tagName){
    for(int i=0; i<_tags.size(); i++){
        if(tagName == _tags.at(i)->tagName ){
            return true;
        }
    }
    return false;
}

/***********************************************
* 获取与某个driver相关的tag集合
* input:   const QString& driverName
* output:  QList<TagParameters*>& _tags
* return:  0  success
 *         -1 failed
**********************************************/
int TagManager::getRelatedTagList(const QString& driverName, QList<TagParameters*>& tagsUsingDriver){
    int ret = -1;
    if( tagName.isEmpty() ){
        return ret;
    }
    tagsUsingDriver.clear();//do not delete!
    for(int i=0; i<_tags.size(); i++){
        for(int j=0; j<_tags.at(i)->driversInfo.size(); j++){
            if(_tags.at(i)->driversInfo.at(j)->driverName == driverName){
                tagsUsingDriver << _tags.at(i);
                ret = 0;//found!
            }
        }
    }
    return ret;
}

/***********************************************
* switch into run state
* input:   none
* output:  none
* return:  0  success
*         -1 failed
* description:
* 1.change state
**********************************************/
int TagManager::stateToConfig(void){
    _state = 0;
}

/***********************************************
* switch into run state
* input:   none
* output:  none
* return:  0  success
*         -1 failed
* description:
* 1.save tags into files/db.
* 2.change state
**********************************************/
int TagManager::stateToRun(void){

    _state = 1;
}

/***********************************************
* get state
* input:   none
* output:  none
* return:  0 config
*          1 run
**********************************************/
int TagManager::getState(void){
    return _state;
}

//////////////////////////////////////////////////////////////////////////end of ITagManager implemention

/***********************************************
* checkName
* input:   QString &name
* return:  0 no conflict
*          1 conflict, auto change name
**********************************************/
bool TagManager::checkName(QString &name){
    bool ret =false;
    bool ok;
    QStringList nameList = getTagsName();
    for(int i=0; i<nameList.size(); i++){
        if(_tags.at(i)->tagName == name){
            ret = true;
            if( tagName.right(1) == ")"){
                int began = tagName.lastIndexOf("(");
                //qDebug()<<tagName<<began;
                if(began != -1){
                    //找到"("
                    began += 1;
                    int chop = began -1;
                    int number = tagName.mid( began, tagName.length()- began -1 ).toInt(&ok);
                    //string right is (dd), increase dd
                    //qDebug()<<number<<ok;
                    if(ok){
                        number ++;
                        tagName = tagName.left(chop) + tr("(%1)").arg(number);
                        //qDebug()<<tagName;
                        i = 0;//search again
                        continue;
                    }
                }
            }
        }
    }
    return ret;
}

QString TagManager::getTagName (const QString& tagID){
    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagID == tagID){
            return _tags.at(i)->tagName;
        }
    }
    return QString::null
}

QString TagManager::getTagID   (const QString& tagName){
    for(int i=0; i<_tags.size(); i++){
        if(_tags.at(i)->tagName == tagName){
            return _tags.at(i)->tagID;
        }
    }
    return QString::null
}
