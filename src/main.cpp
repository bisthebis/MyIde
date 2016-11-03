#include <QtCore>


int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

    QTimer::singleShot(1000, [](){qDebug() << "Leaving..."; qApp->quit();});
	
	return app.exec();

}
