#pragma once


#include <QObject>
#include <QString>


class PrinterTaskStatus: public QObject
{
    Q_OBJECT
public:
    void setMsgDefined(const bool val) { bMsgIsDefined = val; };
    void setMsg(const QString &msg) { mMsg = msg; };
    QString getMsg();
    bool isMsgDefined();

private:
    QString mMsg;
    bool bMsgIsDefined = false;
};
