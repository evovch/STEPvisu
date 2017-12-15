#include "step_visu_2_prj.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    STEP_visu_2_prj w;
    w.show();
    return a.exec();
}
