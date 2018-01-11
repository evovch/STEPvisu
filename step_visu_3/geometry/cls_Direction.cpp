#include "cls_Direction.h"

// Qt
#include <QDebug>

namespace nspGeometry {

cls_Direction::cls_Direction() :
    cls_GeometryEntity(etnDIRECTION),
    mX(0.),
    mY(0.),
    mZ(0.)
{
}

cls_Direction::cls_Direction(double p_x, double p_y, double p_z) :
    cls_GeometryEntity(etnDIRECTION),
    mX(p_x),
    mY(p_y),
    mZ(p_z)
{
}

cls_Direction::~cls_Direction()
{
}

void cls_Direction::Dump(void) const
{
    qDebug().nospace() << "[DIRECTION] " << mX << "\t" << mY << "\t" << mZ;
}

} // End of namespace nspGeometry
