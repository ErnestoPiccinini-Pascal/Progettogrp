#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Structs.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_Carica_clicked();



    void on_CorsixMat_clicked();

    void on_CorsixCog_clicked();

    void on_studentiacorso_clicked();

    void on_excorso_clicked();

    void on_Nstudcorso_clicked();

    void on_Nmatcorso_clicked();

    void on_Matxdesc_clicked();

    void on_newstu_clicked();

    void on_Salvadat_clicked();

    void on_esci_clicked();

private:

    Ui::MainWindow *ui;




};
#endif // MAINWINDOW_H
