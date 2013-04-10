#include "pastebin.h"
#include <QNetworkRequest>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QDebug>
#include <QNetworkAccessManager>

void Pastebin::postToAPI(QString text)
{
    QNetworkRequest *request = new QNetworkRequest(QUrl("http://pastebin.com/api/api_post.php"));
    QUrlQuery *params = new QUrlQuery;
    QNetworkAccessManager *http = new QNetworkAccessManager;

    qDebug() << text;

    params->addQueryItem("api_dev_key", "9506fbcb2eb0bd208627c03a816ae9b9");
    params->addQueryItem("api_option", "paste");
    params->addQueryItem("api_paste_code", text);
    params->addQueryItem("api_paste_name", "QT Pastebin test");
    params->addQueryItem("api_paste_expire_date", "10M");

    connect(http, &QNetworkAccessManager::finished, this, &Pastebin::response);

    http->post(*request, params->toString().toUtf8());
}

void Pastebin::response(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
}
