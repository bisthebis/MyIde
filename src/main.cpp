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
    Dialog_output dialog;
    dialog.show();

    QObject::connect(&launcher, &ProcessLauncher::processClosed,
                     [&](int x) {
        qDebug() << "Process exited with status : " << x;
        auto out = launcher.getStdout();
        if (!out.isEmpty())
            qDebug() << "Output : " << QTextCodec::codecForMib(1016)->toUnicode(out);

        auto err = launcher.getErrors();
        if (!err.isEmpty())
            dialog.setContent(err);
    });

    auto compilers = find_compilers();
    launcher.launchProcess(compilers.first(), {"-v"});
	
	return app.exec();

}
