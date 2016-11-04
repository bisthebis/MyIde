#include "find_fileinfos.hpp"
#include <QStandardPaths>
#include <QFile>
#include <QDir>

QStringList findCompilers()
{
    QString gcc = QStandardPaths::findExecutable("gcc");
    QString clang = QStandardPaths::findExecutable("clang");
    QStringList result;
    if (!gcc.isEmpty())
    {
        result << gcc;
    }
    if (!clang.isEmpty())
    {
        result << clang;
    }

    return result;
}

QStringList findFilesInDir(const QString &dir)
{
    QDir directory(dir);
    QStringList filters = {"*.c", "*.cpp", "*.h", "*.hpp", "*.ui"};
    QStringList list = directory.entryList(filters, QDir::NoDotAndDotDot | QDir::Files | QDir::Readable);
    return list;
}
