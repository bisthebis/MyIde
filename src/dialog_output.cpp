#include "dialog_output.h"
#include "ui_dialog_output.h"

#include <QTextBrowser>
#include <QTextCodec>

Dialog_output::Dialog_output(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_output)
{
    ui->setupUi(this);
}

Dialog_output::~Dialog_output()
{
    delete ui;
}

void Dialog_output::setContent(const QByteArray &src)
{
    QTextBrowser* wid = ui->errors_widget;
    wid->setText(QTextCodec::codecForMib(1016)->toUnicode(src));
}
