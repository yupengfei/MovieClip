#include "processmanager.h"
#include <QProcess>

ProcessManager* ProcessManager::instance = nullptr;

ProcessManager *ProcessManager::getInstance()
{
    if (instance == nullptr) {
            instance = new ProcessManager();
            instance->process = QSharedPointer<QProcess>(new QProcess);
        }
    return instance;
}

void ProcessManager::runShell(QString cmd)
{
    ProcessManager::getInstance()->process->start(cmd);
}

ProcessManager::~ProcessManager()
{

}

ProcessManager::ProcessManager(QObject *parent) : QObject(parent)
{

}
