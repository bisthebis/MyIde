#include <QtCore>
#include <QCoreApplication>
#include <QProcess>

#include "libtmp/find_compilers.hpp"


int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

    auto compilers = find_compilers();

    QProcess* process = new QProcess(&app);
    process->setProcessChannelMode(QProcess::MergedChannels);
    qDebug() << "Launching compiler : " << compilers.first();
    QStringList options = {"-v"};


    QObject::connect(process, &QProcess::readyRead,
                     [process]() {
        qDebug() << "stdout : " << process->readAll();

    });

    QObject::connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
                     [](int code){qDebug() << "Leaving with code : " << code;; qApp->quit();});

    process->start(compilers.first(), options);
    qDebug() << "Process start with options : " << process->arguments();
	
	return app.exec();

}
