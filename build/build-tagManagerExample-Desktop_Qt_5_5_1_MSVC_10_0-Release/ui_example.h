/********************************************************************************
** Form generated from reading UI file 'example.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMPLE_H
#define UI_EXAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_example
{
public:
    QTableView *tableView;
    QPushButton *PB_add;
    QPushButton *PB_delete;
    QPushButton *PB_duplicated;
    QPushButton *PB_load;
    QPushButton *PB_save;

    void setupUi(QWidget *example)
    {
        if (example->objectName().isEmpty())
            example->setObjectName(QStringLiteral("example"));
        example->resize(1009, 628);
        tableView = new QTableView(example);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 70, 471, 331));
        PB_add = new QPushButton(example);
        PB_add->setObjectName(QStringLiteral("PB_add"));
        PB_add->setGeometry(QRect(10, 20, 75, 23));
        PB_delete = new QPushButton(example);
        PB_delete->setObjectName(QStringLiteral("PB_delete"));
        PB_delete->setGeometry(QRect(100, 20, 75, 23));
        PB_duplicated = new QPushButton(example);
        PB_duplicated->setObjectName(QStringLiteral("PB_duplicated"));
        PB_duplicated->setGeometry(QRect(190, 20, 75, 23));
        PB_load = new QPushButton(example);
        PB_load->setObjectName(QStringLiteral("PB_load"));
        PB_load->setGeometry(QRect(350, 20, 75, 23));
        PB_save = new QPushButton(example);
        PB_save->setObjectName(QStringLiteral("PB_save"));
        PB_save->setGeometry(QRect(440, 20, 75, 23));

        retranslateUi(example);

        QMetaObject::connectSlotsByName(example);
    } // setupUi

    void retranslateUi(QWidget *example)
    {
        example->setWindowTitle(QApplication::translate("example", "Form", 0));
        PB_add->setText(QApplication::translate("example", "add...", 0));
        PB_delete->setText(QApplication::translate("example", "delete", 0));
        PB_duplicated->setText(QApplication::translate("example", "duplicate", 0));
        PB_load->setText(QApplication::translate("example", "load...", 0));
        PB_save->setText(QApplication::translate("example", "save...", 0));
    } // retranslateUi

};

namespace Ui {
    class example: public Ui_example {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMPLE_H
