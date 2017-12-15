/**
 * Этот класс, в принципе, реализует элемент структуры данных типа "дерево".
 * Узел может иметь значение, если этот узел терминальный - leaf либо это типизированная функция.
 * (в примере B(A, A) )
 * Также узел может иметь указатель на следующий элемент списка - соседний узел дерева, находящийся на том же уровне.
 * Помимо этого узел может иметь указатель на первый элемент дочерних узлов, если этот узел не терминальный - branch.
 * В процессе синтаксического разбора строки parameter_list типа
 * A, (A, A, A, A, A), A, (B(A, A), B(A, A), A), (A, A)
 * где A - parameter, получается дерево типа
 * A    #    A    #     #
 *    AAAAA     B B A   AA
 *             AA AA
 * где A - терминальная вершина, # - нетерминальная вершина, B - типизированная функция.
 * снизу дети (children), справа - следующий элемент (next)
 */

#ifndef CLS_PARAMETERTREEELEMENT_H
#define CLS_PARAMETERTREEELEMENT_H

#include <map>

class cls_Parameter;
class cls_EIlist;
class cls_EI;

class cls_ParameterTreeElement
{
public: // methods

   /**
    * Конструктор со значением узла, указателем на следующий элемент и
    * указателем на первый элемент в списке дочерних элементов.
    * Возможны 8 вариантов:
    * (current, chldren, next   )
    * (nullptr, nullptr, nullptr)
    * Терминальная вершина без значения ('list' case 2, пустые скобки), последняя на своём уровне
    * (nullptr, nullptr, value  )
    * Терминальная вершина без значения ('list' case 2, пустые скобки), за которой что-то следует на том же уровне
    * (nullptr, value  , nullptr)
    * Ветвь без значения ('list' case 1, непустой список в скобках), последняя на своём уровне
    * (nullptr, value  , value  )
    * Ветвь без значения ('list' case 1, непустой список в скобках), за которой что-то следует на том же уровне
    * (value  , nullptr, nullptr)
    * Терминальная вершина со значением, последняя на своём уровне
    * (value  , nullptr, value  )
    * Терминальная вершина со значением, за которой что-то следует на том же уровне
    * (value  , value  , nullptr)
    * Ветвь со значением (typed_parameter), последняя на своём уровне
    * (value  , value  , value  )
    * Ветвь со значением (typed_parameter), за которой что-то следует на том же уровне
    */
   cls_ParameterTreeElement(cls_Parameter* p_current /*= nullptr*/,
                            cls_ParameterTreeElement* p_children /*= nullptr*/,
                            cls_ParameterTreeElement* p_next /*= nullptr*/);

   /**
    * Стандартный деструктор.
    */
   ~cls_ParameterTreeElement();

   cls_Parameter* GetCurrent() const;
   cls_ParameterTreeElement* GetChildren() const;

   void SetNext(cls_ParameterTreeElement* p_next);
   cls_ParameterTreeElement* GetNext() const;

   cls_Parameter* GetLast() const;

   /**
    * Метод для выброса информации в командную строку. Полезно для debug'а.
    */
   void Dump() const;

   void Link(const cls_EIlist* p_section) const;

   /**
    * Объекта данного класса является указателем и даёт доступ целой ветке.
    * Данный метод проходится по всему дочернему дереву и достаёт сущности по заданному имени.
    */
   std::map<unsigned int, cls_EI*> GetNodesByName(std::string p_filter);

private: // data members
   /**
    * Указатель на текущий параметр  (nullptr, если такого нет).
    */
   cls_Parameter* mCurrent;

   /**
    * Указатель на поддерево дочерних элементов  (nullptr, если такого нет).
    */
   cls_ParameterTreeElement* mChildren;

   /**
    * Указатель на следующий элемент (nullptr, если такого нет)
    */
   cls_ParameterTreeElement* mNext;

};

#endif // CLS_PARAMETERTREEELEMENT_H
