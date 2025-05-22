#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <Qfile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_pushButton_clicked()
{

    //ui->listwidget>clear();
    QString elementi={"ciao"};
    ui->listWidget->addItem(elementi);
    elementi="reggip";
    ui->listWidget->addItem(elementi);
    elementi="bari";
    ui->listWidget->addItem(elementi);
}*/



