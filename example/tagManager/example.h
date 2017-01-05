#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QWidget>
#include <QPaintEvent>
#include <QStandardItemModel>

#include "old_tagmanager.h"

namespace Ui {
class example;
}

class example : public QWidget
{
    Q_OBJECT

public:
    explicit example(QWidget *parent = 0);
    ~example();

    tagManager* mgr;

private:
    void initial();
    Ui::example *ui;
    QStandardItemModel* model;
    QStringList tagIDs;
public slots:
    virtual void paintEvent(QPaintEvent * e);
private slots:
    void updateTagItem(QString tagID);
    void removeTagItem(QString tagID);

    void on_PB_add_clicked();
    void on_PB_delete_clicked();
};

#endif // EXAMPLE_H
