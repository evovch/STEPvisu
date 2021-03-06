﻿/**
 * ISO 10303-42-2000
 * 4.4 Geometry entity definitions
 */

#pragma once

namespace nspGeometry
{
    //TODO develop further
    enum enu_GeometryEntityType {
        etnUNSET,
        etnGEOMETRIC_REPRESENTATION_CONTEXT,
        etnGEOMETRIC_REPRESENTATION_ITEM,
        etnPOINT,
        etnCARTESIAN_POINT,
        etnCYLINDRICAL_POINT,
        etnSPHERICAL_POINT,
        etnPOLAR_POINT,
        etnPOINT_ON_CURVE,
        etnPOINT_ON_SURFACE,
        etnPOINT_IN_VOLUME,
        etnPOINT_REPLICA,
        etnDEGENERATE_PCURVE,
        etnDIRECTION,
        etnVECTOR,
        etnPLACEMENT,
        etnAXIS1_PLACEMENT,
        etnAXIS2_PLACEMENT_2D,
        etnAXIS2_PLACEMENT_3D,
        //TODO fill
        etcCURVE,
        etnLINE,
        etnCONIC,
        etnCIRCLE,
        etnELLLIPSE,
        etnHYPERBOLA,
        etnPARABOLA,
        etnCLOTHOID,
        etnBOUNDED_CURVE,
        etnPOLYLINE
        //TODO and so on
    };

    class cls_GeometryEntity
    {
    public:
        cls_GeometryEntity();
        explicit cls_GeometryEntity(enu_GeometryEntityType p_type);
        ~cls_GeometryEntity(void);

        virtual void Dump(void) const = 0;

    protected:
        enu_GeometryEntityType mType;

    };
} // End of namespace nspGeometry
