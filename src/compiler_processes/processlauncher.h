#ifndef PROCESSLAUNCHER_H
#define PROCESSLAUNCHER_H

#include <QObject>
#include <QProcess>

class QString;
class QStringList;
class QByteArray;

class ProcessLauncher : public QObject
{
    Q_OBJECT
    public:
        explicit ProcessLauncher(QObject *parent = 0);
        const QByteArray& getStdout() const {return _stdout;}
        const QByteArray& getErrors() const {return errors;}


    signals:
        void processClosed(int);
    public slots:
        void launchProcess(const QString& name,
                           const QStringList& args,
                           QProcess::ProcessChannelMode mode = QProcess::SeparateChannels);

    private:
        QByteArray _stdout;
        QByteArray errors;
        QProcess* process = nullptr;

};

#endif // PROCESSLAUNCHER_H
