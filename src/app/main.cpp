#include <QtCore>
#include <QApplication>
#include <QProcess>

#include "compiler_processes/find_fileinfos.hpp"
#include "compiler_processes/processlauncher.h"
#include "project/json_project.h"
#include "dialog_output.h"

int main(int argc, char** argv)
    {
        QApplication app(argc, argv);

        auto compilers = findCompilers();
        auto path = QStandardPaths::standardLocations(QStandardPaths::AppDataLocation).first();
        qDebug() << path;

        //new DialogOutput(nullptr, compilers.first(), {"-v", path + "/main.c", "-o", path + "/MyIDEApplication"}, QProcess::MergedChannels);
        //new DialogOutput(nullptr, "ls", {path}, QProcess::MergedChannels);
        JSONProject project;
        project.open(path + "/project.json");
        qDebug() << "Exec name is : " << project.getExecutableName();
        qDebug() << "Files to compile are : " << project.getFilesList();
        QObject::connect(&project, &JSONProject::buildRequested, [&](QString compiler, QStringList args, QString dir)
            {
                qDebug() << "Build requested. Compiler : " << compiler << ". Arguments : " << args;
                auto dialog = new DialogOutput(nullptr, compiler, args, QProcess::MergedChannels, dir);
            });
        project.build(path);

        return app.exec();

    }
