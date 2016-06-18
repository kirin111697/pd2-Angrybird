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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *slingShot1;
    QLabel *slingShot2;
    QGraphicsView *graphicsView_2;
    QPushButton *quit;
    QPushButton *restart;

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
        MainWindow->setMaximumSize(QSize(1024, 680));
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1024, 680));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMaximumSize(QSize(1024, 680));
        graphicsView->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0);"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        slingShot1 = new QLabel(centralWidget);
        slingShot1->setObjectName(QStringLiteral("slingShot1"));
        slingShot1->setGeometry(QRect(150, 480, 25, 128));
        sizePolicy.setHeightForWidth(slingShot1->sizePolicy().hasHeightForWidth());
        slingShot1->setSizePolicy(sizePolicy);
        slingShot1->setStyleSheet(QStringLiteral("background-image: url(:/new/bg/SLING_SHOT_01_BACK_SMALL.png);"));
        slingShot2 = new QLabel(centralWidget);
        slingShot2->setObjectName(QStringLiteral("slingShot2"));
        slingShot2->setGeometry(QRect(133, 478, 26, 78));
        slingShot2->setStyleSheet(QStringLiteral("background-image: url(:/new/bg/SLING_SHOT_01_FRONT_SMALL.png);"));
        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 1024, 680));
        graphicsView_2->setStyleSheet(QStringLiteral(""));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(890, 640, 115, 32));
        restart = new QPushButton(centralWidget);
        restart->setObjectName(QStringLiteral("restart"));
        restart->setGeometry(QRect(750, 640, 115, 32));
        MainWindow->setCentralWidget(centralWidget);
        graphicsView_2->raise();
        slingShot1->raise();
        graphicsView->raise();
        slingShot2->raise();
        quit->raise();
        restart->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AngryBird", 0));
        slingShot1->setText(QString());
        slingShot2->setText(QString());
        quit->setText(QApplication::translate("MainWindow", "Quit", 0));
        restart->setText(QApplication::translate("MainWindow", "Restart", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
