#include "cls_Placement.h"

// Qt
#include <QDebug>

namespace nspGeometry
{

cls_Placement::cls_Placement() :
    cls_GeometryEntity(etnPLACEMENT),
    mPoint(nullptr)
{
}

cls_Placement::cls_Placement(cls_Cartesian_point* p_point) :
    cls_GeometryEntity(etnPLACEMENT),
    mPoint(p_point)
{
}

cls_Placement::~cls_Placement()
{
}

void cls_Placement::Dump(void) const
{
    qDebug().nospace() << "[PLACEMENT] ";
}

void cls_Placement::SetPoint(cls_Cartesian_point* p_point)
{
    mPoint = p_point;
}

} // End of namespace nspGeometry
