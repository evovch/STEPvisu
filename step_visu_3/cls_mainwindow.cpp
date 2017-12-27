#include "cls_mainwindow.h"
#include "ui_cls_mainwindow.h"

// Qt
#include <QFileDialog>
#include <QDebug>

// Project
#include "stepentities/cls_STEPfile.h"
#include "representations/cls_SolidRepresentation_point.h"

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
    this->BuildSpecTree();

    this->ExtractPoints();
}

void cls_MainWindow::BuildSpecTree(void)
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
    }
}

void cls_MainWindow::ExtractPoints(void)
{
    //TODO here we try to generate the representation and show it in OpenGL.

    ui->statusBar->showMessage("Extracting points...");
    qDebug().nospace() << "Extracting points...";

    // Build representations of separate solids
    std::vector<cls_SolidRepresentation_point*> v_pointRepresentations;
    v_pointRepresentations = mSTEPfile->ExtractPoints();

    //---------------------------------------------------------------------------------------

    // Build one representation for all solids
    cls_SolidRepresentation_point* v_fullPointRepr = new cls_SolidRepresentation_point();
    std::vector<cls_SolidRepresentation_point*>::iterator v_reprIter;
    for (v_reprIter = v_pointRepresentations.begin(); v_reprIter != v_pointRepresentations.end(); ++v_reprIter) {
       v_fullPointRepr->Append(*v_reprIter);
    }

    // Dump the single representation into the OBJ file
/*    QFile v_tmpFile("tmp.obj");
    if (v_tmpFile.open(QIODevice::ReadWrite))
    {
       QTextStream v_stream(&v_tmpFile);
       v_fullPointRepr->DumpToObj(v_stream);
    }
*/
    //---------------------------------------------------------------------------------------

    // Send the v_fullPointRepr to GPU

    //ui->openGLWidget->
    //v_fullPointRepr->SendToGPU();

    ui->statusBar->showMessage("Done extracting points.");
    qDebug().nospace() << "Done extracting points...";

    //v_fullPointRepr->Dump();
}
