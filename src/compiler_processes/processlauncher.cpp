#include "processlauncher.h"

#include <QProcess>
#include <QString>
#include <QStringList>
#include <QByteArray>

ProcessLauncher::ProcessLauncher(QObject *parent) : QObject(parent)
{

}

void ProcessLauncher::launchProcess(const QString &name, const QStringList &args, QProcess::ProcessChannelMode mode)
{
    //Cleanup
    if (process)
    {
        process->close();
        delete process;
    }
    _stdout.clear();
    errors.clear();


    process = new QProcess(this);
    process->setProcessChannelMode(mode);
    QProcess *process_handle = process;
    connect(process, &QProcess::readyReadStandardError,
            [this, process_handle]() {errors.append(process_handle->readAllStandardError());});
    connect(process, &QProcess::readyReadStandardOutput,
            [this, process_handle]() {_stdout.append(process_handle->readAllStandardOutput());});
    connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
            this, &ProcessLauncher::processClosed);

    process->start(name, args);
}
