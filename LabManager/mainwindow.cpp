#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadScriptList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadScriptList()
{
    QStringList scriptList;
    QFile scriptListFile(":/scriptlist.txt");
    scriptListFile.open(QIODevice::ReadOnly);
    QTextStream textStream(&scriptListFile);

    while (!textStream.atEnd())
        scriptList.append(textStream.readLine());

    ui->scriptList->addItems(scriptList);
}

void MainWindow::on_findButton_clicked()
{
    QString searchScript = ui->findScript->text();

    for (int i = 0; i < ui->scriptList->count(); i++) {
        QString itemsScriptList = ui->scriptList->item(i)->text();
        if (!itemsScriptList.contains(searchScript, Qt::CaseInsensitive))
            ui->scriptList->setRowHidden(i, true);
        else
            ui->scriptList->setRowHidden(i, false);
    }

}
