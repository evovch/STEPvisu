#include "cls_CEI.h"

// Qt
#include <QDebug>
#include <QTreeWidget>

// Project
#include "cls_SEI.h"

cls_CEI::cls_CEI() :
    cls_EI(etnCOMPLEX)
{
}

cls_CEI::~cls_CEI()
{
}

void cls_CEI::SetN(const char* p_ninstr)
{
    mN = atoi(&p_ninstr[1]);
}

void cls_CEI::AddSEI(cls_SEI* p_sei)
{
    mSEIs.push_back(p_sei);
}

void cls_CEI::Dump() const
{
    qDebug().nospace() << "[COMPLEX_EI] " << mN;

    //// Loop over the list of simple EIs of the current complex EI and call Dump() for each element
    std::vector<cls_SEI*>::const_iterator v_iter;
    for (v_iter = mSEIs.begin(); v_iter != mSEIs.end(); ++v_iter)
    {
        (*v_iter)->Dump();
    }
}

void cls_CEI::Print() const
{
    qDebug().nospace() << "[COMPLEX_EI] " << mN;
}

void cls_CEI::Link(const cls_EIlist* p_section)
{
    //// Loop over the list of simple EIs of the current complex EI and call Link() for each element
    std::vector<cls_SEI*>::const_iterator iter;
    for (iter = mSEIs.begin(); iter != mSEIs.end(); ++iter)
    {
       (*iter)->Link(p_section);
    }
}

void cls_CEI::GenerateBrepLinks(const cls_EIlist* /*p_section*/)
{
}

void cls_CEI::FillBrepLinks(const cls_EIlist* /*p_section*/)
{
}

void cls_CEI::FillTreeWidget(QTreeWidgetItem* p_treeItem)
{
    //// Loop over the list of simple EIs of the current complex EI and call FillTreeWidget() for each element
    std::vector<cls_SEI*>::const_iterator iter;
    for (iter = mSEIs.begin(); iter != mSEIs.end(); ++iter)
    {
        QTreeWidgetItem* curTreeItem = new QTreeWidgetItem(p_treeItem);
        QString v_valStrQt = QString::fromStdString((*iter)->GetName());
        curTreeItem->setText(0, v_valStrQt);

        (*iter)->FillTreeWidget(curTreeItem);
    }
}
