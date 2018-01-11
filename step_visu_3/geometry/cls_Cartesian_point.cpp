#include "cls_Cartesian_point.h"

#include <QDebug>

namespace nspGeometry {

cls_Cartesian_point::cls_Cartesian_point() :
    mX(0.),
    mY(0.),
    mZ(0.)
{
    mType = etnCARTESIAN_POINT;
}

cls_Cartesian_point::cls_Cartesian_point(double p_x, double p_y, double p_z) :
    mX(p_x),
    mY(p_y),
    mZ(p_z)
{
    mType = etnCARTESIAN_POINT;
}

cls_Cartesian_point::~cls_Cartesian_point()
{
}

void cls_Cartesian_point::Dump() const
{
    qDebug().nospace() << "[CARTESIAN_POINT] " << mX << "\t" << mY << "\t" << mZ;
}

} // End of namespace nspGeometry
