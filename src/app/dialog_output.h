#ifndef DIALOG_OUTPUT_H
#define DIALOG_OUTPUT_H

#include <QDialog>
#include <QByteArray>
#include "compiler_processes/processlauncher.h"

namespace Ui {
class Dialog_output;
}

class DialogOutput : public QDialog
{
    Q_OBJECT

    public:
        explicit DialogOutput(QWidget *parent = nullptr);
        explicit DialogOutput(QWidget *parent,
                              const QString& name,
                              const QStringList& args,
                              QProcess::ProcessChannelMode mode = QProcess::SeparateChannels);
        void setErrorContent(const QByteArray& src);
        void setStdoutContent(const QByteArray& src);

        virtual void closeEvent(QCloseEvent* e) Q_DECL_OVERRIDE;

        ~DialogOutput();

    public slots:
        void UpdateOnFinshedProcess(int);

    private:
        Ui::Dialog_output *ui;
        ProcessLauncher* innerProcess = nullptr;
};

#endif // DIALOG_OUTPUT_H
