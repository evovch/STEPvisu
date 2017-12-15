#include "cls_BREPentity.h"

nspBREP::cls_BREPentity::cls_BREPentity() :
   mType(etnUNSET)
{
}

nspBREP::cls_BREPentity::cls_BREPentity(enu_BREPentityType p_type) :
   mType(p_type)
{
}

nspBREP::cls_BREPentity::~cls_BREPentity()
{
}
