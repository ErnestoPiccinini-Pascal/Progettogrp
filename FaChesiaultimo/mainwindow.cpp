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
#include <Structs.h>
#include <QSet>


//0
QString labels;
QVector<rigav> tutto;
QSet<QString> CodiciCorsi;
QMap<QString,QString> CorsiCodCorso;
//1
QMap<QString,QString> CorsixMatricola;
//2
QMap<QString,QString> CorsixCog;
//3
QMap<QString,QSet<QString>> StudentixCorso;
//4
QMap<QString,QSet<materia>> DatiesamexCorso;
//5=StudentixCorso[CodiciCorsi].size()
//6=DatiesamexCorso[corso].size()
//7=
//8richiamare tutte le map
//9 output su file di vector generale

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

    //ui->listwidget->clear();
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
    labels = in.readLine();
    ui->listWidget->addItem(labels);
    while(!in.atEnd()){

        QString riga=in.readLine();
       // ui->tableWidget->setItem(0,0,new QTableWidgetItem(riga)) ;
        ui->listWidget->addItem(riga);
        QStringList rigapezzi=riga.split(',');
        rigav nuovariga;
        nuovariga={rigapezzi[0],rigapezzi[1],rigapezzi[2],rigapezzi[3],rigapezzi[4],rigapezzi[5],rigapezzi[6]};
        tutto.push_back(nuovariga);
        CorsixMatricola[nuovariga.MatStu]=nuovariga.DesCorso;
        CorsixCog[nuovariga.CogStu]=nuovariga.DesCorso;
        StudentixCorso[nuovariga.CodCorso].insert(nuovariga.CogStu);
         materia matpls={nuovariga.CodMat,nuovariga.DescMat};
        DatiesamexCorso[nuovariga.CodCorso].insert(matpls);
         CodiciCorsi.insert(nuovariga.CodCorso);
        CorsiCodCorso[nuovariga.CodCorso]=nuovariga.DesCorso;
    }
    file.close();
    //hjsdjhfcbjh
    //QMessageBox::information(this, "Contenuto del file", fileContent);
}


void MainWindow::on_CorsixMat_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci Il codice matricola");
    QString Cod=ui->lineEdit->text();
    ui->listWidget->addItem(CorsixMatricola[Cod]);
}


void MainWindow::on_CorsixCog_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci Il Cogn");
    QString Cod=ui->lineEdit->text();
    ui->listWidget->addItem(CorsixCog[Cod]);
}


void MainWindow::on_studentiacorso_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci Il Codice del corso");
    QString Cod=ui->lineEdit->text();
    for( QString x: StudentixCorso[Cod]){
        ui->listWidget->addItem(x);
    }
}


void MainWindow::on_excorso_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci Il Codice del corso");
    QString Codi=ui->lineEdit->text();
    for( auto x: DatiesamexCorso[Codi]){
        QString outp;
        outp="Codice Esame : " + x.Cod + " Descrizione Esame : " + x.Desc;
        ui->listWidget->addItem(outp);
    }
}


void MainWindow::on_Nstudcorso_clicked()
{
    ui->listWidget->clear();
    //ui->label->setText("inserisci Il Codice del corso");
    //QString Cod=ui->lineEdit->text();
    for(auto x:CodiciCorsi){
        QString outp= CorsiCodCorso[x]+ " : " + QString::number(StudentixCorso[x].size());
        ui->listWidget->addItem(outp);
    }
}



void MainWindow::on_Nmatcorso_clicked()
{
    ui->listWidget->clear();
    //ui->label->setText("inserisci Il Codice del corso");
    //QString Cod=ui->lineEdit->text();
    for(auto x:CodiciCorsi){
        QString outp= CorsiCodCorso[x]+ " : " + QString::number(DatiesamexCorso[x].size());
        ui->listWidget->addItem(outp);
    }
}



void MainWindow::on_Matxdesc_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci la string da cercare");
    QString Cod=ui->lineEdit->text();
    for(auto x:tutto){
        if(x.DescMat.contains(Cod)){
            QString outp=x.strun();
            ui->listWidget->addItem(outp);
        }
    }
}


void MainWindow::on_newstu_clicked()
{
    ui->listWidget->clear();
    ui->label->setText("inserisci i dati del nuovo studente come da documento ");
    QString riga=ui->lineEdit->text();
    QStringList rigapezzi=riga.split(',');
    rigav nuovariga;
    nuovariga={rigapezzi[0],rigapezzi[1],rigapezzi[2],rigapezzi[3],rigapezzi[4],rigapezzi[5],rigapezzi[6]};
    tutto.push_back(nuovariga);
    CorsixMatricola[nuovariga.MatStu]=nuovariga.DesCorso;
    CorsixCog[nuovariga.CogStu]=nuovariga.DesCorso;
    StudentixCorso[nuovariga.CodCorso].insert(nuovariga.CogStu);
    materia matpls={nuovariga.CodMat,nuovariga.DescMat};
    DatiesamexCorso[nuovariga.CodCorso].insert(matpls);
    CodiciCorsi.insert(nuovariga.CodCorso);
    CorsiCodCorso[nuovariga.CodCorso]=nuovariga.DesCorso;
}


void MainWindow::on_Salvadat_clicked()
{
    QFile file("output.txt");  // crea un file nella cartella del progetto

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out<<labels;
        for(auto x: tutto){
            out<<x.strun()<<"\n";
        }
        file.close();
    } else {
        qDebug() << "Errore nell'apertura del file!";
    }
}


void MainWindow::on_esci_clicked()
{
    QApplication::quit();
}

