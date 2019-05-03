#ifndef QRDLG_H
#define QRDLG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include "ui_qrdlg.h"
#include <qevent.h>
#include <qjsonobject.h>
#include <qjsondocument.h>
#include <qjsonarray.h>
#include <QBuffer>
class QrDlg : public QDialog
{
    Q_OBJECT

public:
    explicit QrDlg(QWidget *parent = Q_NULLPTR);
    ~QrDlg();
    void getQrCodeFromServer();
    void showBase64Image(QString base64Code);
    bool eventFilter(QObject *obj, QEvent *event);
    void pollingQrCodeStatus(QString uuid);
    void timerEvent(QTimerEvent *event);
    QString account;
    bool scanSuccess;
    void showEvent(QShowEvent *);
public slots:
    void replayFinished(QNetworkReply *reply);
private:
    Ui::QrDlg ui;
    QNetworkAccessManager * manager;
    QNetworkReply *reply_qrCode;
    QNetworkReply *reply_pollingResult;
    QString uuid;
    int timerId;

    QString baseIp;
};

#endif // QRDLG_H
