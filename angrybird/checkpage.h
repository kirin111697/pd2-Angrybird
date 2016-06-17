#ifndef CHECKPAGE_H
#define CHECKPAGE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class checkPage;
}

class checkPage : public QWidget
{
    Q_OBJECT

public:
    explicit checkPage(QWidget *parent = 0);
    ~checkPage();

private slots:
    void on_PushBotton_clicked();

private:
    Ui::checkPage *ui;
    MainWindow *mainw;
};

#endif // CHECKPAGE_H
