#include "cls_EI.h"

cls_EI::cls_EI(enu_EItype p_type) :
    mType(p_type),
    mN(0)
{
}

cls_EI::cls_EI(enu_EItype p_type, unsigned int p_n) :
    mType(p_type),
    mN(p_n)
{
}

cls_EI::~cls_EI(void)
{
}
