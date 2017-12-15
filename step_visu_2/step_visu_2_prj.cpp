#include "step_visu_2_prj.h"

#include <QString>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <iostream>

#include "cls_GLTimer.h"

#include "representations/cls_SolidRepresentation_point.h"

extern FILE* yyin;
extern int yyparse(cls_STEPfile*& myStepFile);

STEP_visu_2_prj::STEP_visu_2_prj(QWidget *parent)
    : QMainWindow(parent),
    mSTEPfile(nullptr)
{
    ui.setupUi(this);
    ui.pteFile->setPlainText("C:\\DEVELOPMENT\\Secret_STEP_files\\English_names\\1.stp");
}

STEP_visu_2_prj::~STEP_visu_2_prj()
{

}

void STEP_visu_2_prj::SelectFile()
{
   QString v_filename;
   v_filename = QFileDialog::getOpenFileName(this, tr("Open STEP file"), "", tr("STEP files(*.stp *.step)"));

   if (!v_filename.isEmpty()) {
      ui.pteFile->setPlainText(v_filename);
   }
}

unsigned int STEP_visu_2_prj::ParseFile()
{
   QString v_filenameQt = ui.pteFile->toPlainText();

   FILE* inFile = fopen(v_filenameQt.toLatin1(), "r");

   if (!inFile) {
      ui.statusBar->showMessage("Failed to open input file.");

      return 1;
   } else {
      yyin = inFile;
      int res;
      ui.statusBar->showMessage("Parsing input file...");
      std::cout << "Parsing input file..." << std::endl;
      cls_GLTimer v_timer;
      v_timer.Start();

      res = yyparse(mSTEPfile);

      std::cout << "Done parsing input file. " << v_timer.Stop() << std::endl;

      switch (res) {
      case 0: ui.statusBar->showMessage("Parsed input file."); break;
      case 1: ui.statusBar->showMessage("Error parsing input file."); break;
      case 2: ui.statusBar->showMessage("Error parsing input file: memory exhausted."); break;
      default: break;
      }

      fclose(inFile);

      return 0;
   }
}

void STEP_visu_2_prj::ListByFilter()
{
   QString v_qtFilter;
   v_qtFilter = ui.leFilter->displayText();

   QString v_message("Listing by filter ");
   v_message += v_qtFilter;
   ui.statusBar->showMessage(v_message);

   std::string v_filter;
   v_filter = v_qtFilter.toUtf8().constData();

   std::vector<std::string> v_listOfProducts;
   v_listOfProducts = mSTEPfile->ListByFilter(v_filter);

   std::string v_strCpp;
   QString v_strQt;

   std::vector<std::string>::iterator v_iter;
   for (v_iter = v_listOfProducts.begin(); v_iter != v_listOfProducts.end(); ++v_iter) {
      v_strCpp = *v_iter;
      v_strQt = QString(v_strCpp.c_str());
      ui.lstList->addItem(v_strQt);
   }

   v_message = "Done listing by filter ";
   v_message += v_qtFilter;
   ui.statusBar->showMessage(v_message);
}

void STEP_visu_2_prj::ListSolids()
{
   QString v_qtfilter("MANIFOLD_SOLID_BREP");
   ui.leFilter->setText(v_qtfilter);
   this->ListByFilter();
}

void STEP_visu_2_prj::ListProducts()
{
   QString v_qtfilter("PRODUCT");
   ui.leFilter->setText(v_qtfilter);
   this->ListByFilter();
}

void STEP_visu_2_prj::ExtractPoints()
{
   //TODO here we try to generate the representation and show it in OpenGL.

   ui.statusBar->showMessage("Extracting points...");

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
   QFile v_tmpFile("tmp.obj");
   if (v_tmpFile.open(QIODevice::ReadWrite))
   {
      QTextStream v_stream(&v_tmpFile);
      v_fullPointRepr->DumpToObj(v_stream);
   }
   
   //---------------------------------------------------------------------------------------

   // Send the v_fullPointRepr to GPU
   ui.openGLWidget->SetRepresentation(v_fullPointRepr);
   ui.openGLWidget->SendRepresentationToGPU();

   //TODO
   // Виталий!
   // Здесь v_pointRepresentations - вектор объектов типа представление солида с помощью точек.
   // Один элемент вектора - некий массив точек, он является простейшим графическим представлением тела.
   // см. класс cls_SolidRepresentation_point - просто вектор точек
   // твоя задача выкинуть в любой формат точки, сгруппированные по солидам и разобраться как импортировать
   // эти данные из собственноручно разработанного плагина Blender.

   ui.statusBar->showMessage("Done extracting points.");
   
   //v_fullPointRepr->Dump();
}