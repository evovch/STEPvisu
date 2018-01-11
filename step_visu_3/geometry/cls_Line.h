/**
 * ISO 10303-42-2000
 * 4.4.24 line
 */

#pragma once

#include "cls_GeometryEntity.h" // mother class

namespace nspGeometry
{
    class cls_Cartesian_point;
    class cls_Direction;

    class cls_Line : public cls_GeometryEntity
    {
    public:
        cls_Line();
        cls_Line(cls_Cartesian_point* p_point, cls_Direction* p_direction);
        ~cls_Line();

        /**
        * Метод для выброса информации в командную строку. Полезно для debug'а.
        */
        void Dump(void) const;

        void SetPoint(cls_Cartesian_point* p_point) { mPoint = p_point; }
        void SetDirection(cls_Direction* p_direction) { mDirection = p_direction; }

        cls_Cartesian_point* GetPoint(void) const { return mPoint; }
        cls_Direction* GetDirection(void) const { return mDirection; }

    private:
        cls_Cartesian_point* mPoint;
        cls_Direction* mDirection;

    };
} // End of namespace nspGeometry
