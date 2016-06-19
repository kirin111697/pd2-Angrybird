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
        checkPage->resize(550, 500);
        checkPage->setStyleSheet(QStringLiteral("background-image: url(:/new/bg/story-image.png);"));
        PushBotton = new QPushButton(checkPage);
        PushBotton->setObjectName(QStringLiteral("PushBotton"));
        PushBotton->setGeometry(QRect(220, 360, 101, 61));
        PushBotton->setStyleSheet(QLatin1String("background-color: rgba(255, 173, 108, 64);\n"
"font: 24pt \"Courier New\";"));

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
