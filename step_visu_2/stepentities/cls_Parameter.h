/**
 * Класс, представляющий параметр.
 */

#pragma once

#include <string>

class cls_EI;
class cls_EIlist;

class cls_Parameter
{
public: // methods
    explicit cls_Parameter(std::string p_value);
    explicit cls_Parameter(const char* p_value);
    ~cls_Parameter(void);

    /**
     * Метод для выброса информации в командную строку. Полезно для debug'а.
     */
    void Dump(void) const;

    /**
     * Возвращает mValue как какой-то определённый тип.
     * Такие методы применяются, когда делается предположение о том,
     * чей это параметр, какой сущности (напр. CARTESIAN_POINT имеет 3 координта типа double).
     */

    unsigned long GetValAsULong(void) const;
    int GetValAsInt(void) const;
    float GetValAsFloat(void) const;
    double GetValAsDouble(void) const;
    std::string GetValAsString(void) const;

    cls_EI* GetPointer(void) const;

    void Link(const cls_EIlist* p_section);

private: // data members
    /**
     * Значение параметра как строка. Может содержать как строку, так и какое-то особое значение, записанное в строку.
     */
    std::string mValue;

    /**
     * Если параметр является ссылкой на другую сущсность, то помимо строки вида "#N"
     * хранится указатель на эту сущность. Эти указатели заполняются в процессе Link'овки.
     */
    cls_EI* mPointer;

};
