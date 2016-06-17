/********************************************************************************
** Form generated from reading UI file 'checkpage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPAGE_H
#define UI_CHECKPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_checkPage
{
public:
    QPushButton *PushBotton;

    void setupUi(QWidget *checkPage)
    {
        if (checkPage->objectName().isEmpty())
            checkPage->setObjectName(QStringLiteral("checkPage"));
        checkPage->resize(400, 300);
        PushBotton = new QPushButton(checkPage);
        PushBotton->setObjectName(QStringLiteral("PushBotton"));
        PushBotton->setGeometry(QRect(140, 170, 115, 32));

        retranslateUi(checkPage);

        QMetaObject::connectSlotsByName(checkPage);
    } // setupUi

    void retranslateUi(QWidget *checkPage)
    {
        checkPage->setWindowTitle(QString());
        PushBotton->setText(QApplication::translate("checkPage", "play", 0));
    } // retranslateUi

};

namespace Ui {
    class checkPage: public Ui_checkPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPAGE_H
