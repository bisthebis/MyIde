#include <QtCore>
#include <QApplication>
#include <QProcess>

#include "compiler_processes/find_fileinfos.hpp"
#include "compiler_processes/processlauncher.h"
#include "dialog_output.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    auto compilers = find_compilers();
    auto path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
    qDebug() << path;

    new DialogOutput(nullptr, compilers.first(), {"-v", path + "/main.c", "-o", path + "/MyIDEApplication"}, QProcess::MergedChannels);
    new DialogOutput(nullptr, "ls", {path}, QProcess::MergedChannels);


    return app.exec();

}
