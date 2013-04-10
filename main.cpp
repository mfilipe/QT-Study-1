#include <QApplication>
#include <QtQuick/QQuickView>
#include <QQmlContext>
#include "pastebin.h"

int main(int argc, char *argv[])
{
    QApplication qapp(argc, argv);

    QQuickView *qtstudy = new QQuickView;
    Pastebin *pastebin = new Pastebin;

    qtstudy->rootContext()->setContextProperty("qapp", &qapp);
    qtstudy->rootContext()->setContextProperty("qpastebin", pastebin);

    qtstudy->setSource(QUrl("qrc:/qml/qtstudy.qml"));
    qtstudy->show();

    return qapp.exec();
}
