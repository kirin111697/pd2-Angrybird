#include "checkpage.h"
#include "ui_checkpage.h"

checkPage::checkPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::checkPage),
    mainw(new MainWindow)
{
    ui->setupUi(this);
    mainw->show();
}

checkPage::~checkPage()
{
    delete ui;
}

void checkPage::on_PushBotton_clicked()
{
    this->hide();
    mainw->startGame();
}
