#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCursor>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString windowTitle;

private slots:
    void on_actionBold_triggered();

    void on_actionItalic_triggered();

    void on_actionUnderline_triggered();

    void on_actionSave_triggered();

    void on_action18_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_action12_triggered();

    void on_action16_triggered();

    void on_actionSave_As_triggered();
private:
    Ui::MainWindow *ui;

    QString nomeDelFile;

    void aggiornaTitolo();

    void textCursor(QString before, QString after);

};

#endif // MAINWINDOW_H
