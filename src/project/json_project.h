#ifndef JSON_PROJECT_H
#define JSON_PROJECT_H

#include <QStringList>
#include <QObject>

class JSONProject : public QObject {

    Q_OBJECT

    public:
        QStringList getFilesList() const {return files;}
        QString getExecutableName() const {return executableName;}
        void open(const QString& name);
        void build(const QString& workingDir);

        enum BuildType {Plain};

    signals:
        void buildRequested(QString, QStringList, QString);

    private:
        QStringList files;
        QString executableName;
};

#endif // JSON_PROJECT_H
