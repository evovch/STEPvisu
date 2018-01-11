/**
 * ISO 10303-42-2000
 * 4.4.16 placement
 */

#pragma once

#include "cls_GeometryEntity.h" // mother class

namespace nspGeometry
{
    class cls_Cartesian_point;

    class cls_Placement : public cls_GeometryEntity
    {
    public:
        cls_Placement();
        explicit cls_Placement(cls_Cartesian_point* p_point);
        ~cls_Placement();

        /**
         * Метод для выброса информации в командную строку. Полезно для debug'а.
         */
        void Dump(void) const;

        void SetPoint(cls_Cartesian_point* p_point);

        cls_Cartesian_point* GetPoint(void) const { return mPoint; }

    private:
        cls_Cartesian_point* mPoint;

    };
} // End of namespace nspGeometry
