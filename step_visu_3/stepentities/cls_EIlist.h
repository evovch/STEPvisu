/**
 * Данный класс хранит в себе список data сущностей - entity instance'ов.
 */

#pragma once

// STL
#include <map>
#include <string>

class QTreeWidget;

class cls_EI;

class cls_EIlist
{
public: // methods
    cls_EIlist();
    ~cls_EIlist(void);

    /**
     * Добавить в список новую сущность.
     */
    void AddEI(unsigned int p_n, cls_EI* p_ei);

    /**
     * Метод для выброса информации в командную строку. Полезно для debug'а.
     */
    void Dump(void) const;

    void Link(void);

    void GenerateAndFillBrepLinks(void);

    void FillTreeWidget(QTreeWidget* p_treeWidget);

    void FillTreeWidgetBREP(QTreeWidget* p_treeWidget);

    cls_EI* GetEIbyN(unsigned int p_n) const;

    /**
     * Нати все сущности с заданным именем и вернуть нумерованным списком.
     */
    std::map<unsigned int, cls_EI*> Find(std::string p_filter) const;

    /**
     * Лишь обёртка над таким же методом с аргументов типа строка C++
     */
    std::map<unsigned int, cls_EI*> Find(const char* p_filter) const;

private: // data members
    /**
     * @brief List of entity instances
     */
    std::map<unsigned int, cls_EI*> mEIs;

};
