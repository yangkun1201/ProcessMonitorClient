#include "util.h"
#include <QFile>
#include <qevent.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include "QDebug"

Util* Util::instance = NULL;

Util::Util()
{
    baseIp = "";
}

QString Util::getBaseIp()
{
    if(baseIp != "")
    {
        return baseIp;
    }else{
        QString val;
        QFile file;
        file.setFileName("../config/config.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        val = file.readAll();
        file.close();
        qWarning() << "config: "<<val;
        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(val.toUtf8(),&jsonError);
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError))
        {
            if (doucment.isObject())
            {
                QJsonObject objs = doucment.object();
                if (objs.contains("baseIp"))
                {
                    QJsonValue value = objs.value("baseIp");
                    baseIp = value.toString();
                }
            }
        }
        return baseIp;
    }
}

void Util::setAccount(QString account)
{
    this->account = account;
}

QString Util::getAccount()
{
    return this->account;
}

