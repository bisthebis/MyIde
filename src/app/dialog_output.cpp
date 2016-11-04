#include "dialog_output.h"
#include "ui_dialog_output.h"

#include <QTextBrowser>
#include <QTextCodec>
#include <QDebug>

DialogOutput::DialogOutput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_output)
{
    ui->setupUi(this);
    setWindowTitle("Output of command");
}

DialogOutput::DialogOutput(QWidget *parent,
                           const QString &name,
                           const QStringList &args,
                           QProcess::ProcessChannelMode mode) : DialogOutput(parent)
{
    innerProcess = new ProcessLauncher(this);
    innerProcess->launchProcess(name, args, mode);
    QObject::connect(innerProcess, &ProcessLauncher::processClosed, this, &DialogOutput::UpdateOnFinshedProcess);
    show();
}
void DialogOutput::UpdateOnFinshedProcess(int code)
{
    setWindowTitle(tr("Process exited with status %0.").arg(code));
    setStdoutContent(innerProcess->getStdout());
    setErrorContent(innerProcess->getErrors());


}

void DialogOutput::closeEvent(QCloseEvent *)
{
    deleteLater();
}

DialogOutput::~DialogOutput()
{
    delete ui;
    qDebug() << "Closed DialogOutput";
}

void DialogOutput::setErrorContent(const QByteArray &src)
{
    //auto string = QTextCodec::codecForMib(1016)->toUnicode(src); //Seems to crash in Windows
    auto string = src;
    ui->errors_widget->setText(string);
}
void DialogOutput::setStdoutContent(const QByteArray &src)
{
    //auto string = QTextCodec::codecForMib(1016)->toUnicode(src); //Seems to crash in Windows
    auto string = src;
    ui->stdout_widget->setText(string);
}
