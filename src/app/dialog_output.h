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
    void setContent(const QByteArray& src);
    ~DialogOutput();

private:
    Ui::Dialog_output *ui;
};

#endif // DIALOG_OUTPUT_H
