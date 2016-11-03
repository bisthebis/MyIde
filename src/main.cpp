#include <QtCore>
#include <QCoreApplication>
#include <QProcess>


int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

    QProcess* process = new QProcess(&app);
    process->start("chromium");

    /* Weird cast because of overloaded signal */
    QObject::connect(process, static_cast<void(QProcess::*)(int, QProcess::ExitStatus)>(&QProcess::finished),
                     &app, &QCoreApplication::quit);
	
	return app.exec();

}
