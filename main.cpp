#include "mainwindow.h"
#include "contact.h"
#include "numero.h"
#include <QtXml/QtXml>
#include <QPushButton>
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Dans tous les cas, on doit fermer le document XML : on n'en a plus besoin, tout est compris dans l'objet DOM.

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "TP_Contact_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    Contact c;
    MainWindow w;
    w.setWindowTitle("vos contact");
  //  QPushButton btn("bonjour", &w);
    w.show();
    return a.exec();
}
