#include "dialog_output.h"
#include "ui_dialog_output.h"

#include <QTextBrowser>
#include <QTextCodec>

DialogOutput::DialogOutput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_output)
{
    ui->setupUi(this);
}

DialogOutput::~DialogOutput()
{
    delete ui;
}

void DialogOutput::setContent(const QByteArray &src)
{
    //auto string = QTextCodec::codecForMib(1016)->toUnicode(src); //Seems to crash in Windows
    auto string = src;
    ui->errors_widget->setText(string);
}
