#include <QtCore>
#include <QApplication>
#include <QProcess>

#include "compiler_processes/find_compilers.hpp"
#include "compiler_processes/processlauncher.h"
#include "dialog_output.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    ProcessLauncher launcher;
    DialogOutput dialog;
    dialog.show();

    QObject::connect(&launcher, &ProcessLauncher::processClosed,
                     [&](int x) {
        qDebug() << "Process exited with status : " << x;
        auto out = launcher.getStdout();
        if (!out.isEmpty())
            dialog.setStdoutContent(out);

        auto err = launcher.getErrors();
        if (!err.isEmpty())
            dialog.setErrorContent(err);
    });

    auto compilers = find_compilers();
    auto path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    qDebug() << path;
    launcher.launchProcess(compilers.first(), {"-v", path + "/main.c", "-o", path + "/MyIDEApplication"}, QProcess::MergedChannels);
	
	return app.exec();

}
