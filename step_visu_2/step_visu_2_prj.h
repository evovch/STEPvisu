#pragma once

#include <QMainWindow> // mother class

#include "ui_step_visu_2_prj.h"

class cls_STEPfile;

class STEP_visu_2_prj : public QMainWindow
{
    Q_OBJECT

public:
   explicit STEP_visu_2_prj(QWidget *parent = 0);
    ~STEP_visu_2_prj();

public slots:
    void SelectFile();
    unsigned int  ParseFile();

    void ListByFilter();
    void ListSolids();
    void ListProducts();
    void ExtractPoints();

private:
    Ui::STEP_visu_2_prjClass ui;
    cls_STEPfile* mSTEPfile;

};
