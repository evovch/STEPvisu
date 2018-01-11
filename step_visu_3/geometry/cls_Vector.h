/**
 * ISO 10303-42-2000
 * 4.4.15 vector
 */

#pragma once

#include "cls_GeometryEntity.h" // mother class

namespace nspGeometry
{
    class cls_Direction;

    class cls_Vector : public cls_GeometryEntity
    {
    public:
        cls_Vector();
        cls_Vector(cls_Direction* p_direction, double p_magnitude);
        ~cls_Vector();

        /**
         * Метод для выброса информации в командную строку. Полезно для debug'а.
         */
        void Dump(void) const;

        void SetDirection(cls_Direction* p_direction);
        void SetMagnitude(double p_magnitude);

        cls_Direction* GetDirection(void) const { return mDirection;  }
        double GetMagnitude(void) const { return mMagnitude; }

    private:
        cls_Direction* mDirection;
        double mMagnitude;

    };
} // End of namespace nspGeometry
