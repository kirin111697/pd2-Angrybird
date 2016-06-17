/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *slingShot1;
    QLabel *slingShot2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(1080, 720));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, -1, 1024, 681));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMaximumSize(QSize(1280, 720));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        slingShot1 = new QLabel(centralWidget);
        slingShot1->setObjectName(QStringLiteral("slingShot1"));
        slingShot1->setGeometry(QRect(180, 382, 39, 199));
        sizePolicy.setHeightForWidth(slingShot1->sizePolicy().hasHeightForWidth());
        slingShot1->setSizePolicy(sizePolicy);
        slingShot1->setStyleSheet(QStringLiteral("background-image: url(:/new/bg/Angry Birds Seasons/Angry Birds Seasons/SLING_SHOT_01_BACK.png);"));
        slingShot2 = new QLabel(centralWidget);
        slingShot2->setObjectName(QStringLiteral("slingShot2"));
        slingShot2->setGeometry(QRect(152, 377, 41, 121));
        slingShot2->setStyleSheet(QStringLiteral("background-image: url(:/new/bg/Angry Birds Seasons/Angry Birds Seasons/SLING_SHOT_01_FRONT.png);"));
        MainWindow->setCentralWidget(centralWidget);
        slingShot1->raise();
        graphicsView->raise();
        slingShot2->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AngryBird", 0));
        slingShot1->setText(QString());
        slingShot2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
