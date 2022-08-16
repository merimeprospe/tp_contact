#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include <QtSql>
#include <QSqlDatabase>
#include "connexion_MSQL.h"
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Sauvegarder_clicked();
    void affichargeDonneUtuilisateur();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_tableView_pressed(const QModelIndex &index);

    void on_tableView_destroyed(QObject *arg1);

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *modele;
};
#endif // MAINWINDOW_H
