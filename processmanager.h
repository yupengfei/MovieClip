#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <QObject>
#include <QSharedPointer>
class QProcess;

class ProcessManager : public QObject
{
    Q_OBJECT
public:
    static ProcessManager * getInstance();
    Q_INVOKABLE void runShell(QString cmd);
    ~ProcessManager();
signals:

public slots:
private:
    static ProcessManager * instance;

    explicit ProcessManager(QObject *parent = nullptr);
    QSharedPointer<QProcess> process;
};

#endif // PROCESSMANAGER_H
