/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *Carica;
    QPushButton *CorsixMat;
    QPushButton *CorsixCog;
    QPushButton *studentiacorso;
    QPushButton *excorso;
    QPushButton *Nstudcorso;
    QPushButton *Nmatcorso;
    QPushButton *Matxdesc;
    QPushButton *newstu;
    QPushButton *Salvadat;
    QPushButton *esci;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(50, 20, 541, 331));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(610, 21, 147, 326));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Carica = new QPushButton(layoutWidget);
        Carica->setObjectName("Carica");

        verticalLayout->addWidget(Carica);

        CorsixMat = new QPushButton(layoutWidget);
        CorsixMat->setObjectName("CorsixMat");

        verticalLayout->addWidget(CorsixMat);

        CorsixCog = new QPushButton(layoutWidget);
        CorsixCog->setObjectName("CorsixCog");

        verticalLayout->addWidget(CorsixCog);

        studentiacorso = new QPushButton(layoutWidget);
        studentiacorso->setObjectName("studentiacorso");

        verticalLayout->addWidget(studentiacorso);

        excorso = new QPushButton(layoutWidget);
        excorso->setObjectName("excorso");

        verticalLayout->addWidget(excorso);

        Nstudcorso = new QPushButton(layoutWidget);
        Nstudcorso->setObjectName("Nstudcorso");

        verticalLayout->addWidget(Nstudcorso);

        Nmatcorso = new QPushButton(layoutWidget);
        Nmatcorso->setObjectName("Nmatcorso");

        verticalLayout->addWidget(Nmatcorso);

        Matxdesc = new QPushButton(layoutWidget);
        Matxdesc->setObjectName("Matxdesc");

        verticalLayout->addWidget(Matxdesc);

        newstu = new QPushButton(layoutWidget);
        newstu->setObjectName("newstu");

        verticalLayout->addWidget(newstu);

        Salvadat = new QPushButton(layoutWidget);
        Salvadat->setObjectName("Salvadat");

        verticalLayout->addWidget(Salvadat);

        esci = new QPushButton(layoutWidget);
        esci->setObjectName("esci");

        verticalLayout->addWidget(esci);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Carica->setText(QCoreApplication::translate("MainWindow", "Carica dati", nullptr));
        CorsixMat->setText(QCoreApplication::translate("MainWindow", "Corsi per matricola", nullptr));
        CorsixCog->setText(QCoreApplication::translate("MainWindow", "Corsi per cognome", nullptr));
        studentiacorso->setText(QCoreApplication::translate("MainWindow", "Studenti iscritti a un corso", nullptr));
        excorso->setText(QCoreApplication::translate("MainWindow", "Esami per corso", nullptr));
        Nstudcorso->setText(QCoreApplication::translate("MainWindow", "N studenti corso", nullptr));
        Nmatcorso->setText(QCoreApplication::translate("MainWindow", "N materie corso", nullptr));
        Matxdesc->setText(QCoreApplication::translate("MainWindow", "Materie per descrizione", nullptr));
        newstu->setText(QCoreApplication::translate("MainWindow", "Nuovo studente", nullptr));
        Salvadat->setText(QCoreApplication::translate("MainWindow", "Salva dati su file", nullptr));
        esci->setText(QCoreApplication::translate("MainWindow", "Esci", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
