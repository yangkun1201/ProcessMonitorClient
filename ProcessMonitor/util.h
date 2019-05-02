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

private:
    Util();
    QString baseIp;
    static Util* instance;
};

#endif // UTIL_H
