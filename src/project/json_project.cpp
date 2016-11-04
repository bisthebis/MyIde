#include "json_project.h"
#include <QtCore>

void JSONProject::open(const QString &name)
    {
        QFile file(name);
        if (!file.open(QIODevice::ReadOnly))
            {
                qDebug() << "Couldn't open file";
                return;
            }

        QByteArray data = file.readAll();

        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);
        if (doc.isNull())
            {
                qDebug() << "Failed parsing document. Error is : " << error.errorString();
                return;
            }

        executableName = doc.object().value("execname").toString();
        auto fileNamesArray = doc.object().value("files").toArray();
        for (const auto& e : fileNamesArray)
            {
                files << e.toString();
            }

        return;
    }


void JSONProject::build(const QString& workingDir)
    {
        QStringList parameters;
        parameters << files << "-o" << executableName << "-v";
        emit buildRequested("gcc", parameters, workingDir);
    }
