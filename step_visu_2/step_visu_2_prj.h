#ifndef STEP_VISU_2_PRJ_H
#define STEP_VISU_2_PRJ_H

#include <QtWidgets/QMainWindow>
#include "ui_step_visu_2_prj.h"
#include "stepentities/cls_STEPfile.h"

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

#endif // STEP_VISU_2_PRJ_H
