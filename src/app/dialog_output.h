#ifndef DIALOG_OUTPUT_H
#define DIALOG_OUTPUT_H

#include <QDialog>
#include <QByteArray>
namespace Ui {
class Dialog_output;
}

class DialogOutput : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOutput(QWidget *parent = 0);
    void setErrorContent(const QByteArray& src);
    void setStdoutContent(const QByteArray& src);

    ~DialogOutput();

private:
    Ui::Dialog_output *ui;
};

#endif // DIALOG_OUTPUT_H
