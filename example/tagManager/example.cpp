#include "example.h"
#include "ui_example.h"

example::example(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::example)
{
    ui->setupUi(this);
    mgr = new  tagManager(this);
    connect(mgr,SIGNAL(msgTagItemChanged(QString)),this,SLOT(updateTagItem(QString)));
    connect(mgr,SIGNAL(msgTagItemRemoved(QString)),this,SLOT(removeTagItem(QString)));
    initial();
}

example::~example()
{
    delete ui;
}

void example::paintEvent(QPaintEvent * e){
    ui->tableView->resize( this->width(), this->height()-80 );
    QWidget::paintEvent( e);
}

void example::initial(){
    model = new QStandardItemModel(this);

    model->setHorizontalHeaderItem(0, new QStandardItem( QString::fromLocal8Bit("ID")));
    model->setHorizontalHeaderItem(1, new QStandardItem( QString::fromLocal8Bit("名称")));
    model->setHorizontalHeaderItem(2, new QStandardItem( QString::fromLocal8Bit("类型")));
    model->setHorizontalHeaderItem(3, new QStandardItem( QString::fromLocal8Bit("初始值")));
    model->setHorizontalHeaderItem(4, new QStandardItem( QString::fromLocal8Bit("质量代码")));
    model->setHorizontalHeaderItem(5, new QStandardItem( QString::fromLocal8Bit("值")));
    model->setHorizontalHeaderItem(6, new QStandardItem( QString::fromLocal8Bit("最后更新")));
    model->setHorizontalHeaderItem(7, new QStandardItem( QString::fromLocal8Bit("有新值写入")));

    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::SelectedClicked);
    ui->tableView->setVerticalScrollMode( QAbstractItemView::ScrollPerItem );
    ui->tableView->setModel(model);
    tagIDs = mgr->getTagItemsID();
    int index;
    for (index =0; index <tagIDs.length() ; index++){
        model->setItem(index,0,new QStandardItem( tagIDs[index] ) );
        model->setItem(index,1,new QStandardItem( mgr->getTagItem( tagIDs[index] )->getName() ) );
        model->setItem(index,2,new QStandardItem(  QString::number(mgr->getTagItem( tagIDs[index] )->getType() )  ) );
    }

}

void example::on_PB_add_clicked()
{
    mgr->insertTagItem();
}


void example::updateTagItem(QString tagID){
    //qDebug()<<"example::updateTagItem"<<"step1";
    int index;
    for (index =0; index <model->rowCount() ; index++){
        if(model->item(index,0)->text() == tagID){
            break;
        }
    }
    //qDebug()<<"example::updateTagItem"<<"step2";

    //qDebug()<<"example::updateTagItem"<<"step3";
    if(index == model->rowCount()){
        //新增行
        model->setItem(index,0,new QStandardItem( tagID ) );
        model->setItem(index,1,new QStandardItem( mgr->getTagItem( tagID )->getName() ) );
        model->setItem(index,2,new QStandardItem( QString::number(mgr->getTagItem( tagID )->getType() )   ) );
        tagIDs = mgr->getTagItemsID();
    }
    else{
        //修改行
        QStandardItem* tempItem = model->item(index,1);
        tempItem->setText( mgr->getTagItem( tagID )->getName() );
        tempItem = model->item(index,2);
        tempItem->setText( QString::number(mgr->getTagItem( tagID )->getType() ) );
    }
}

void example::removeTagItem(QString tagID){
    int index;
    for (index =0; index <model->rowCount() ; index++){
        if(model->item(index,0)->text() == tagID){
            break;
        }
    }
    if(index < model->rowCount()){
        //删除行
        model->removeRow(index);
    }
}

void example::on_PB_delete_clicked(){

    QItemSelectionModel* selectArea = ui->tableView->selectionModel();
    QModelIndexList selectTags = selectArea->selectedRows(0);
    QStringList removeList;
    foreach(QModelIndex index, selectTags){
         removeList<<index.data().toString();
    }
    foreach (QString ID, removeList){
         mgr->deleteTagItem(ID);
    }
}
