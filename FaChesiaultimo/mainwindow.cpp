#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QMainWindow>
#include <QListWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QString>
#include <QDir>

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




void MainWindow::on_Carica_clicked()
{
    qDebug() << QDir::currentPath();
    QFile file("../../corsi_studenti.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Errore", "Impossibile aprire il file");
        return;
    }

    QTextStream in(&file);
    QString fileContent = in.readAll();
    ui->listWidget->addItem(fileContent);
    file.close();

    //QMessageBox::information(this, "Contenuto del file", fileContent);
}

