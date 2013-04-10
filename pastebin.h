#ifndef PASTEBIN_H
#define PASTEBIN_H

#include <QObject>
#include <QNetworkReply>

class Pastebin : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE void postToAPI(QString text);
    
signals:
    
public slots:
    void response(QNetworkReply *reply);
    
};

#endif // PASTEBIN_H
