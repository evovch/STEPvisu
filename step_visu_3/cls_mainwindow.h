#ifndef CLS_MAINWINDOW_H
#define CLS_MAINWINDOW_H

#include <QMainWindow> // mother class

class cls_STEPfile;

namespace Ui {
class cls_MainWindow;
}

class cls_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cls_MainWindow(QWidget *parent = 0);
    ~cls_MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionPRODUCT_triggered();

private:
    Ui::cls_MainWindow *ui;

    cls_STEPfile* mSTEPfile;

    void BuildSpecTree(void);
    void ExtractPoints(void);
};

#endif // CLS_MAINWINDOW_H
