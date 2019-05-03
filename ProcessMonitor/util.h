#ifndef UTIL_H
#define UTIL_H

#include <QObject>

class Util:QObject
{
    Q_OBJECT
public:
    QString getBaseIp();
    static Util* getInstance()
    {
        if(instance == NULL)
        {
            instance = new Util();
        }
        return instance;
    }
    void setAccount(QString account);
    QString getAccount();

private:
    Util();
    QString baseIp;
    QString account;
    static Util* instance;
};

#endif // UTIL_H
