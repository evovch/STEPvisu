#include "cls_mainwindow.h"
#include "ui_cls_mainwindow.h"

// Qt
#include <QFileDialog>
#include <QDebug>

// Project
#include "stepentities/cls_STEPfile.h"

extern FILE* yyin;
extern int yyparse(cls_STEPfile*& myStepFile);

cls_MainWindow::cls_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cls_MainWindow)
{
    ui->setupUi(this);
}

cls_MainWindow::~cls_MainWindow()
{
    delete ui;
}

// Parse the input STEP file here
void cls_MainWindow::on_actionOpen_triggered()
{
    QString v_filenameQt = QFileDialog::getOpenFileName(this,
        tr("Open STEP file"), "", tr("STEP Files (*.stp *.step)"));

    FILE* v_inFile = fopen(v_filenameQt.toLatin1(), "r");

    if (!v_inFile) {
       ui->statusBar->showMessage("Failed to open input file.");
       qDebug().nospace() << "Failed to open input file.";
       return;
    } else {
        yyin = v_inFile;
        int res;

        ui->statusBar->showMessage("Parsing input file...");
        qDebug().nospace() << "Parsing input file...";

        res = yyparse(mSTEPfile);

        qDebug().nospace() << "Done parsing input file.";

        switch (res) {
        case 0: ui->statusBar->showMessage("Parsed input file.");
            qDebug().nospace() << "Parsed input file.";
            break;
        case 1: ui->statusBar->showMessage("Error parsing input file.");
            qDebug().nospace() << "Error parsing input file.";
            break;
        case 2: ui->statusBar->showMessage("Error parsing input file: memory exhausted.");
            qDebug().nospace() << "Error parsing input file: memory exhausted.";
            break;
        default: break;
        }

        fclose(v_inFile);
        return;
    }

}

void cls_MainWindow::on_actionPRODUCT_triggered()
{
    if (!mSTEPfile) {
        qDebug() << "No file imported.";
        return;
    }

    mSTEPfile->Link();
    mSTEPfile->GenerateAndFillBrepLinks();

    //mSTEPfile->Dump();

    this->BuildSpecTree();
}

void cls_MainWindow::BuildProductsList(void)
{
    std::string v_filter("PRODUCT");
    std::vector<std::string> v_listOfProducts;
    v_listOfProducts = mSTEPfile->ListByFilter(v_filter);

    std::string v_strCpp;
    QString v_strQt;
    std::vector<std::string>::iterator v_iter;
    for (v_iter = v_listOfProducts.begin(); v_iter != v_listOfProducts.end(); ++v_iter) {
       v_strCpp = *v_iter;
       v_strQt = QString(v_strCpp.c_str());
       qDebug().nospace() << v_strQt;

       QTreeWidgetItem* curItem = new QTreeWidgetItem(ui->treeWidget);
       curItem->setText(0, v_strQt);
    }
}

void cls_MainWindow::BuildSpecTree(void)
{
    //mSTEPfile->FillTreeWidget(ui->treeWidget);
    mSTEPfile->FillTreeWidgetBREP(ui->treeWidget);
}
