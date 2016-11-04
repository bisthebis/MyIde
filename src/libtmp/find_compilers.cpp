#include "find_compilers.hpp"
#include <QStandardPaths>

QStringList find_compilers()
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
