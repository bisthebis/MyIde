#include <QtCore>
#include <QCoreApplication>
#include <QProcess>

#include "compiler_processes/find_compilers.hpp"
#include "compiler_processes/processlauncher.h"

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

    ProcessLauncher launcher;
    QObject::connect(&launcher, &ProcessLauncher::processClosed,
                     [&](int x) {
        qDebug() << "Process exited with status : " << x;
        auto out = launcher.getStdout();
        if (!out.isEmpty())
            qDebug() << "Output : " << QTextCodec::codecForMib(1016)->toUnicode(out);

        auto err = launcher.getErrors();
        if (!err.isEmpty())
            qDebug() << "Errors : " << QTextCodec::codecForMib(1016)->toUnicode(err);
    });

    auto compilers = find_compilers();
    launcher.launchProcess(compilers.first(), {"-v"});
	
	return app.exec();

}
