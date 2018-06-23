#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextDocumentFragment>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nomeDelFile = "Nuovo.html";
    ui->textEdit->setPlainText("");
    aggiornaTitolo();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    nomeDelFile = "Nuovo.html";
    ui->textEdit->setPlainText("");

    aggiornaTitolo();
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Seleziona il file da Aprire");

    //Se file ha dei contenuti
    if(!file.isEmpty()){
        QFile sFile(file);
        if(sFile.open(QFile::ReadWrite)){
            QTextStream in(&sFile);
            QString testo = in.readAll();
            sFile.close();

            ui->textEdit->setAcceptRichText(true);
            ui->textEdit->setHtml(testo);

            nomeDelFile = file;
        }
    }

    aggiornaTitolo();
}

void MainWindow::on_actionSave_triggered()
{
    QFile sFile(nomeDelFile);
    if(sFile.open(QFile::ReadWrite)){
        QTextStream out(&sFile);

        out << ui->textEdit->toHtml();

        sFile.flush();
        sFile.close();
    }

    aggiornaTitolo();
}

void MainWindow::on_actionSave_As_triggered()
{
    nomeDelFile = QFileDialog::getSaveFileName(this, "Salva Con Nome");
    on_actionSave_triggered();
}



void MainWindow::on_actionBold_triggered()
{
    textCursor("<b>", "</b>");
}

void MainWindow::on_actionItalic_triggered()
{
    textCursor("<i>", "</i>");
}

void MainWindow::on_actionUnderline_triggered()
{
    textCursor("<span style='text-decoration:underline'>", "</span>");
}



void MainWindow::on_action12_triggered()
{
    textCursor("<span style='font-size:12px'>", "</span>");
}

void MainWindow::on_action16_triggered()
{
    textCursor("<span style='font-size:16px'>", "</span>");
}

void MainWindow::on_action18_triggered()
{
    textCursor("<span style='font-size:18px'>", "</span>");
}



/**
 * @brief Cambia il titolo della window quando viene caricato un nuovo file
 */
void MainWindow::aggiornaTitolo(){
    windowTitle = "Editor di Testo - " + nomeDelFile;
    this->setWindowTitle(windowTitle);
}




void MainWindow::textCursor(QString before, QString after)
{

//    qDebug() << textCursor();
//    qDebug() << (textCursor().charFormat());
    QTextCursor tc = ui->textEdit->textCursor();
    QTextDocumentFragment theFragment =  tc.selection();
    QString theHtml = theFragment.toPlainText();
    qDebug() << theHtml;
    QString htmlStirng = before + theHtml + after;
    tc.insertHtml(htmlStirng);
    qDebug() << htmlStirng;
}
