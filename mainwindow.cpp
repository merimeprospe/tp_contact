#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include <QtXml/QtXml>

QString val("O");

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vraiconnexionBD();
    affichargeDonneUtuilisateur();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Sauvegarder_clicked()
{
 /* QSqlDatabase conn=QSqlDatabase::addDatabase("QMYSQL");
  conn.setHostName("127.0.0.1");
  conn.setUserName("root");
  conn.setPassword("");
  conn.setDatabaseName("contact");


  if(conn.open()){
     QMessageBox::information(this,"Connection","la base de donne a ete connecter avec success");
  } else
  {
     QMessageBox::information(this,"Not Connected","la base de donne n'a pas put ce connecter");
     qDebug() << conn.lastError();
     QMessageBox::information(this,"",conn.lastError().text());


  }*/

 // QSqlQuery requete;
//-----------------------------------------------------------------

  QString nom = ui->nom->text();;
  QString prenom = ui->prenom->text();;
  QString sexe = ui->sexe->currentText();
  QString numero = ui->numero->text();
  QString numero1 = ui->numero1->text();
  QString numero2 = ui->numero2->text();
  QString email =  ui->email->text();
  if (nom == "")
  {
      nom="aucun";
  }
  if (prenom == "")
  {
      prenom="aucun";
  }
  if (numero=="")
  {
      numero="aucun";
  }
  if (numero1=="")
  {
      numero1="aucun";
  }
  if (numero2=="")
  {
      numero2="aucun";
  }
  if (email=="")
  {
      email="aucun";
  }
  QFile file("contact_stk.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Append ))
  {
        QTextStream flux(&file);
        flux<<" " << nom <<" " << prenom <<" " << sexe <<" " << numero <<" " << numero1 <<" " << numero2 <<" " << email << Qt::endl;
        file.close();
  }
  affichargeDonneUtuilisateur();

  ui->nom->setText("");
  ui->prenom->setText("");
  ui->numero->setText("");
  ui->numero1->setText("");
  ui->numero2->setText("");
  ui->email->setText("");
 /* requete.prepare("insert into contact(nom,prenom,sexe,numero1,numero2,numero3,) values(:nom,:prenom,:sexe,:numero,:numero1,:numero2)");
  requete.bindValue(":nom",nom);
  requete.bindValue(":prenom",prenom);
  requete.bindValue(":sexe",sexe);
  requete.bindValue(":numero",numero);
  requete.bindValue(":numero1",numero1);
  requete.bindValue(":numero2",numero2);
  requete.exec();
  //QMessageBox::information(this,"Envoi vers BD","Envoi complet");*/
}

void MainWindow::affichargeDonneUtuilisateur()
{
  /* QSqlQuery requete; int ligne(0);
   requete.exec("select count(*) from contac");
   while(requete.next()){
     ligne=requete.value(0).toInt();
   }*/
   int ligne(0);
   QString li;
   QFile file("contact_stk.txt");
   if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
   {
       QTextStream flux(&file);
       while (! flux.atEnd())
       {
           li = flux.readLine();
          // QMessageBox::information(this,"Envoi vers BD", li);
           ligne++;
       }
       file.close();

    }
   if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
   {
       QTextStream flux(&file);
       modele = new QStandardItemModel(ligne,7);
       QString mot;
       int i,j;
       for (i=0;i<ligne;i++)
       {
           for(j=0;j<7;j++)
           {
               if (! flux.atEnd())
               {
                     flux >>mot ;
                     QStandardItem* item = new QStandardItem(mot);
                     //modele->setData(modele->index(i,j), mot , Qt::DisplayRole);
                     modele->setItem(i,j,item);
                     //QMessageBox::information(this,"Envoi vers BD", mot);
               }

           }
       }
       modele->setHeaderData(0,Qt::Horizontal,"Nom");
       modele->setHeaderData(1,Qt::Horizontal,"Prenom");
       modele->setHeaderData(2,Qt::Horizontal,"Sexe");
       modele->setHeaderData(3,Qt::Horizontal,"Numero");
       modele->setHeaderData(4,Qt::Horizontal,"Numero1");
       modele->setHeaderData(5,Qt::Horizontal,"Numero2");
       modele->setHeaderData(6,Qt::Horizontal,"Email");


       ui->tableView->setModel(modele);

   }

}

void MainWindow::on_pushButton_clicked()
{
    int n(0),m(0);
    QStringList mot;
    QString r = ui->recherche->text();
    QString li;
    int i(-1),s(0);
    QFile file("contact_stk.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QTextStream flux(&file);
        while (! flux.atEnd())
        {
            li = flux.readLine();
            if(li.contains(r, Qt::CaseInsensitive))
            {
                s++;
            }

        }
        file.close();
    }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {

        modele = new QStandardItemModel(s,7);
        QTextStream flux(&file);
        while (! flux.atEnd())
        {
            li = flux.readLine();

            if(li.contains(r, Qt::CaseInsensitive))
            {
                 n=-1;
                 i++;
                 m=0;
                  mot = li.split(" ");
                 for (QList<QString>::Iterator it = mot.begin();it !=mot.end(); ++it)
                 {
                   m++;
                   if(m>=2)
                   {
                      //QMessageBox::information(this,"Envoi vers BD", *it);
                       n++;
                       QStandardItem* item = new QStandardItem(*it);
                       modele->setItem(i,n,item);
                   }
                 }

            }

        }
      //  modele->setHeaderData(0,Qt::Horizontal,"resulta de votre rechercher");

        modele->setHeaderData(0,Qt::Horizontal,"Nom");
        modele->setHeaderData(1,Qt::Horizontal,"Prenom");
        modele->setHeaderData(2,Qt::Horizontal,"Sexe");
        modele->setHeaderData(3,Qt::Horizontal,"Numero");
        modele->setHeaderData(4,Qt::Horizontal,"Numero1");
        modele->setHeaderData(5,Qt::Horizontal,"Numero2");
        modele->setHeaderData(6,Qt::Horizontal,"Email");

        ui->tableView->setModel(modele);
        //ui->tableView->horizontalHeader()->setStretchLastSection(true);
        file.close();
        //ui->tableView->rowAt();

     }
}


void MainWindow::on_pushButton_3_clicked()
{
    int ligne(0);
    QString li;
    QFile file("contact_stk.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QTextStream flux(&file);
        while (! flux.atEnd())
        {
            li = flux.readLine();
           // QMessageBox::information(this,"Envoi vers BD", li);
            ligne++;
        }
        file.close();

     }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QTextStream flux(&file);
        modele = new QStandardItemModel(ligne,7);
        QString mot;
        int i,j;
        for (i=0;i<ligne;i++)
        {
            for(j=0;j<7;j++)
            {
                if (! flux.atEnd())
                {
                      flux >>mot ;
                      QStandardItem* item = new QStandardItem(mot);
                      //modele->setData(modele->index(i,j), mot , Qt::DisplayRole);
                      modele->setItem(i,j,item);
                      //QMessageBox::information(this,"Envoi vers BD", mot);
                }

            }
        }
        modele->setHeaderData(0,Qt::Horizontal,"Nom");
        modele->setHeaderData(1,Qt::Horizontal,"Prenom");
        modele->setHeaderData(2,Qt::Horizontal,"Sexe");
        modele->setHeaderData(3,Qt::Horizontal,"Numero");
        modele->setHeaderData(4,Qt::Horizontal,"Numero1");
        modele->setHeaderData(5,Qt::Horizontal,"Numero2");
        modele->setHeaderData(6,Qt::Horizontal,"Email");


        ui->tableView->setModel(modele);

    }
    ui->recherche->setText("");

    ui->nom->setText("");
    ui->prenom->setText("");
    ui->numero->setText("");
    ui->numero1->setText("");
    ui->numero2->setText("");
    ui->email->setText("");
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    val=ui->tableView->model()->data(index).toString();
    val=" "+val+" ";
    int indexRow = ui->tableView->selectionModel()->currentIndex().row();
   // QMessageBox::information(this,"Envoi vers BD", indexRow);
   // val[n] = ' ';
    //ui->tableView->rowAt();

}

void MainWindow::on_pushButton_2_clicked()
{
    if(val!="O")
    {
        QString li;
        int indexRow = ui->tableView->selectionModel()->currentIndex().row()+1;
        int s(0),n(0);
        QFile file("contact_stk.txt");
        QFile file_1("contact.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            while (! flux.atEnd())
            {
                li = flux.readLine();
                n++;
                if(indexRow==n)
                {
                    s++;
                }
                else
                {

                   // QMessageBox::information(this,"Envoi vers BD", "le fichier222222 n'a pas put s'ouffrire");
                    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append ))
                    {
                          QTextStream flux_1(&file_1);
                          flux_1 << li << Qt::endl;
                          file_1.close();
                    }
                    else
                    {
                        QMessageBox::information(this,"Envoi vers BD", "le fichier n'a pas put s'ouffrire");
                    }
                }

            }
            file_1.close();
            file.remove();
            QFile file_1("contact_stk.txt");
            QFile file("contact.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
            {
                QTextStream flux(&file);
                while (! flux.atEnd())
                {
                    li = flux.readLine();
                    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append ))
                    {
                        QTextStream flux_1(&file_1);
                        flux_1 << li << Qt::endl;
                        file_1.close();
                    }
                    else
                    {
                        QMessageBox::information(this,"Envoi vers BD", "le fichier n'a pas put s'ouffrire");
                    }

                }
            }
            file_1.close();
            file.remove();
        }
        //-------------------------------------------------------
        int ligne(0);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            while (! flux.atEnd())
            {
                li = flux.readLine();
               // QMessageBox::information(this,"Envoi vers BD", li);
                ligne++;
            }
            file.close();

         }
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            modele = new QStandardItemModel(ligne,7);
            QString mot;
            int i,j;
            for (i=0;i<ligne;i++)
            {
                for(j=0;j<7;j++)
                {
                    if (! flux.atEnd())
                    {
                          flux >>mot ;
                          QStandardItem* item = new QStandardItem(mot);
                          //modele->setData(modele->index(i,j), mot , Qt::DisplayRole);
                          modele->setItem(i,j,item);
                          //QMessageBox::information(this,"Envoi vers BD", mot);
                    }

                }
            }
            modele->setHeaderData(0,Qt::Horizontal,"Nom");
            modele->setHeaderData(1,Qt::Horizontal,"Prenom");
            modele->setHeaderData(2,Qt::Horizontal,"Sexe");
            modele->setHeaderData(3,Qt::Horizontal,"Numero");
            modele->setHeaderData(4,Qt::Horizontal,"Numero1");
            modele->setHeaderData(5,Qt::Horizontal,"Numero2");
            modele->setHeaderData(6,Qt::Horizontal,"Email");


            ui->tableView->setModel(modele);
        }
        val="O";
    }else
    {
        QMessageBox::information(this,"Envoi vers BD", "vous n'avez pas selectionner de contact");
    }

}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    val=ui->tableView->model()->data(index).toString();
    val=" "+val+" ";
    int n(-1);
    int indexRow = ui->tableView->selectionModel()->currentIndex().row() +1;
    QStringList mot;
    QString li;
    int i(0),s(0),k(0),m(0),j(-1),t(0);
    QFile file("contact_stk.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        QTextStream flux(&file);
        while (! flux.atEnd())
        {
            li = flux.readLine();
            t++;
            if(indexRow==t)
            {
                if(li.contains(val, Qt::CaseInsensitive))
                {
                    s++;
                }
            }

        }
     file.close();
        t=0;
    }
    if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
    {
        modele = new QStandardItemModel(s,7);
        QTextStream flux(&file);
        while (! flux.atEnd())
        {
            li = flux.readLine();
            t++;
           if(indexRow==t)
            {
               if(li.contains(val, Qt::CaseInsensitive))
               {
                   i=1;
                 k=-1;
                 j++;
                 m=0;
                 mot = li.split(" ");
                 for (QList<QString>::Iterator it = mot.begin();it !=mot.end(); ++it)
                 {
                     n++;
                    // QMessageBox::information(this,"Envoi vers BD", *it);
                     if(n==1)
                     {
                         ui->nom->setText(*it);
                     }
                     if(n==2)
                     {
                         ui->prenom->setText(*it);
                     }
                     if(n==4)
                     {
                         ui->numero->setText(*it);
                     }
                     if(n==5)
                     {
                         ui->numero1->setText(*it);
                     }
                     if(n==6)
                     {
                         ui->numero2->setText(*it);
                     }
                     if(n==7)
                     {
                         ui->email->setText(*it);
                     }
                     m++;
                     if(m>=2)
                     {
                        //QMessageBox::information(this,"Envoi vers BD", *it);
                         k++;
                         QStandardItem* item = new QStandardItem(*it);
                         modele->setItem(j,k,item);
                     }

                 }
                 n=0;
               }
            }

        }
        if(i==1)
        {
            //modele->setHeaderData(0,Qt::Horizontal,"le comtact que vous souhaiter modifier");
            modele->setHeaderData(0,Qt::Horizontal,"Nom");
            modele->setHeaderData(1,Qt::Horizontal,"Prenom");
            modele->setHeaderData(2,Qt::Horizontal,"Sexe");
            modele->setHeaderData(3,Qt::Horizontal,"Numero");
            modele->setHeaderData(4,Qt::Horizontal,"Numero1");
            modele->setHeaderData(5,Qt::Horizontal,"Numero2");
            modele->setHeaderData(6,Qt::Horizontal,"Email");


            ui->tableView->setModel(modele);
            ui->tableView->horizontalHeader()->setStretchLastSection(true);
        }

        file.close();
        //ui->tableView->rowAt();

     }
}

void MainWindow::on_tableView_entered(const QModelIndex &index)
{

}





void MainWindow::on_pushButton_4_clicked()
{
    if(val!="O")
    {
        QString li;

        int s(0);
        QFile file("contact_stk.txt");
        QFile file_1("contact.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            while (! flux.atEnd())
            {
                li = flux.readLine();
                if(li.contains(val, Qt::CaseInsensitive))
                {
                    QString nom = ui->nom->text();
                    QString prenom = ui->prenom->text();
                    QString sexe = ui->sexe->currentText();
                    QString numero = ui->numero->text();
                    QString numero1 = ui->numero1->text();
                    QString numero2 = ui->numero2->text();
                    QString email = ui->email->text();
                    if (nom == "")
                    {
                        nom="aucun";
                    }
                    if (prenom == "")
                    {
                        prenom="aucun";
                    }
                    if (numero=="")
                    {
                        numero="aucun";
                    }
                    if (numero1=="")
                    {
                        numero1="aucun";
                    }
                    if (numero2=="")
                    {
                        numero2="aucun";
                    }
                    if (email=="")
                    {
                        email="aucun";
                    }
                    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append ))
                    {
                          QTextStream flux(&file_1);
                          flux<<" " << nom <<" " << prenom <<" " << sexe <<" " << numero <<" " << numero1 <<" " << numero2 <<" " << email << Qt::endl;
                          file_1.close();
                    }

                    ui->nom->setText("");
                    ui->prenom->setText("");
                    ui->numero->setText("");
                    ui->numero1->setText("");
                    ui->numero2->setText("");
                    ui->email->setText("");
                }
                else
                {

                   // QMessageBox::information(this,"Envoi vers BD", "le fichier222222 n'a pas put s'ouffrire");
                    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append ))
                    {
                          QTextStream flux_1(&file_1);
                          flux_1 << li << Qt::endl;
                          file_1.close();
                    }
                    else
                    {
                        QMessageBox::information(this,"Envoi vers BD", "le fichier n'a pas put s'ouffrire");
                    }
                }

            }
            file_1.close();
            file.remove();
            QFile file_1("contact_stk.txt");
            QFile file("contact.txt");
            if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
            {
                QTextStream flux(&file);
                while (! flux.atEnd())
                {
                    li = flux.readLine();
                    if (file_1.open(QIODevice::WriteOnly | QIODevice::Append ))
                    {
                        QTextStream flux_1(&file_1);
                        flux_1 << li << Qt::endl;
                        file_1.close();
                    }
                    else
                    {
                        QMessageBox::information(this,"Envoi vers BD", "le fichier n'a pas put s'ouffrire");
                    }

                }
            }
            file_1.close();
            file.remove();
        }
        int ligne(0);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            while (! flux.atEnd())
            {
                li = flux.readLine();
               // QMessageBox::information(this,"Envoi vers BD", li);
                ligne++;
            }
            file.close();

         }
        if (file.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
            QTextStream flux(&file);
            modele = new QStandardItemModel(ligne,7);
            QString mot;
            int i,j;
            for (i=0;i<ligne;i++)
            {
                for(j=0;j<7;j++)
                {
                    if (! flux.atEnd())
                    {
                          flux >>mot ;
                          QStandardItem* item = new QStandardItem(mot);
                          //modele->setData(modele->index(i,j), mot , Qt::DisplayRole);
                          modele->setItem(i,j,item);
                          //QMessageBox::information(this,"Envoi vers BD", mot);
                    }

                }
            }
            modele->setHeaderData(0,Qt::Horizontal,"Nom");
            modele->setHeaderData(1,Qt::Horizontal,"Prenom");
            modele->setHeaderData(2,Qt::Horizontal,"Sexe");
            modele->setHeaderData(3,Qt::Horizontal,"Numero");
            modele->setHeaderData(4,Qt::Horizontal,"Numero1");
            modele->setHeaderData(5,Qt::Horizontal,"Numero2");
            modele->setHeaderData(6,Qt::Horizontal,"Email");


            ui->tableView->setModel(modele);
        }
        val="O";
    }else
    {
        QMessageBox::information(this,"Envoi vers BD", "vous n'avez pas selectionner de contact");
    }

}

