#include "cls_Parameter.h"

// Qt
#include <QDebug>

// Project
#include "cls_EIlist.h"

cls_Parameter::cls_Parameter(std::string p_value) :
    mValue(p_value),
    mPointer(nullptr)
{
}

cls_Parameter::cls_Parameter(const char* p_value) :
    mPointer(nullptr)
{
    std::string v_cppstring(p_value);
    mValue = v_cppstring;
    //qDebug().nospace() << "Creating parameter from value " << p_value << ". size=" << mValue.size();
}

cls_Parameter::~cls_Parameter(void)
{
}

void cls_Parameter::Dump(void) const
{
    qDebug().nospace() << "[PARAMETER] " << mValue.c_str();
}


/* Компактненько */
unsigned long cls_Parameter::GetValAsULong(void) const
{   return std::stoul(mValue); }
int cls_Parameter::GetValAsInt(void) const
{   return std::stoi(mValue); }
float cls_Parameter::GetValAsFloat(void) const
{   return std::stof(mValue); }
double cls_Parameter::GetValAsDouble(void) const
{   return std::stod(mValue); }
std::string cls_Parameter::GetValAsString(void) const
{   return mValue; }


cls_EI* cls_Parameter::GetPointer() const
{
   return mPointer;
}

void cls_Parameter::Link(const cls_EIlist* p_section)
{
   // Нашли ссылку, прицепить объект к тому, на который он ссылается
   if (mValue[0] == '#') {
      unsigned int v_refN = std::stoul(&mValue[1]);
      this->mPointer = p_section->GetEIbyN(v_refN);
   }
}
