#ifndef DIALOG_OUTPUT_H
#define DIALOG_OUTPUT_H

#include <QDialog>
#include <QByteArray>
namespace Ui {
class Dialog_output;
}

class Dialog_output : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_output(QWidget *parent = 0);
    void setContent(const QByteArray& src);
    ~Dialog_output();

private:
    Ui::Dialog_output *ui;
};

#endif // DIALOG_OUTPUT_H
