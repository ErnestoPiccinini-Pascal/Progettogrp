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
#include <QFileDialog>
#include <QInputDialog>

//0
QMap<QString,QString> MatCodMat;
QMap<QString,QString> CodCorsoxCodMat;
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
    QString path=QFileDialog::getOpenFileName(this, "Apri file");
    QFile file(path);
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
         CodCorsoxCodMat[nuovariga.CodMat]=nuovariga.CodCorso;
        MatCodMat[nuovariga.CodMat]=nuovariga.CodMat;
    }
    file.close();
    //hjsdjhfcbjh
    //QMessageBox::information(this, "Contenuto del file", fileContent);
}


void MainWindow::on_CorsixMat_clicked()
{
    QString Cod=QInputDialog::getText(
        this,                          // parent
        "Inserisci codice matricola",             // titolo finestra
        "Inserire codice matricola",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
    //ui->label->setText("inserisci Il codice matricola");
    ui->listWidget->addItem(CorsixMatricola[Cod]);
}


void MainWindow::on_CorsixCog_clicked()
{
    QString Cod=QInputDialog::getText(
        this,                          // parent
        "Inserisci cognome",             // titolo finestra
        "Qual è il cognome da ricercare?",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
   // ui->label->setText("inserisci Il Cogn");
    ui->listWidget->addItem(CorsixCog[Cod]);
}


void MainWindow::on_studentiacorso_clicked()
{
    QString Cod=QInputDialog::getText(
        this,                          // parent
        "Inserisci codice corso",             // titolo finestra
        "Inserire codice corso",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
   // ui->label->setText("inserisci Il Codice del corso");
   // QString Cod=ui->lineEdit->text();
    for( QString x: StudentixCorso[Cod]){
        ui->listWidget->addItem(x);
    }
}


void MainWindow::on_excorso_clicked()
{
    QString Codi=QInputDialog::getText(
        this,                          // parent
        "Inserisci codice corso",             // titolo finestra
        "Inserire codice corso",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
  //  ui->label->setText("inserisci Il Codice del corso");
   // QString Codi=ui->lineEdit->text();
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
    QString Cod=QInputDialog::getText(
        this,                          // parent
        "Inserisci parola chiave",             // titolo finestra
        "Inserire stringa da cercare",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
   // ui->label->setText("inserisci la string da cercare");
   // QString Cod=ui->lineEdit->text();
    for(auto x:tutto){
        if(x.DescMat.toUpper().contains(Cod.toUpper())){
            QString outp=x.strun();
            ui->listWidget->addItem(outp);
        }
    }
}


void MainWindow::on_newstu_clicked()
{

    rigav nuovariga;
    nuovariga.CodMat=QInputDialog::getText(
        this,                          // parent
        "Inserisci Codice di una Materia",             // titolo finestra
        "Inserire Codice Materia",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    if(!CodCorsoxCodMat.contains(nuovariga.CodMat)){
        QMessageBox::warning(this, "Errore", "non esiste la materia");
        return;
    }
    nuovariga.MatStu=QInputDialog::getText(
        this,                          // parent
        "Inserisci Codice matricola",             // titolo finestra
        "Inserire codice matricola",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    nuovariga.NomStu=QInputDialog::getText(
        this,                          // parent
        "Inserisci nome",             // titolo finestra
        "Inserire nome",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    nuovariga.CogStu=QInputDialog::getText(
        this,                          // parent
        "Inserisci Cognome",             // titolo finestra
        "Inserire Cognome",        // testo nel box
        QLineEdit::Normal,            // modalità inserimento (normale o password)
        ""                         // testo di default
        // indica se l’utente ha premuto OK o Annulla
        );
    ui->listWidget->clear();
    //ui->label->setText("inserisci i dati del nuovo studente come da documento ");
   // QString riga=ui->lineEdit->text();
    nuovariga.CodCorso=CodCorsoxCodMat[nuovariga.CodMat];
    nuovariga.DesCorso=CorsiCodCorso[nuovariga.CodCorso];
    nuovariga.DescMat=MatCodMat[nuovariga.CodMat];
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
    QFile file("output.csv");  // crea un file nella cartella del progetto

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

