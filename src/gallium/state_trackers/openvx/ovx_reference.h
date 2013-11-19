#ifndef _OVX_REFERENCE_H
#define _OVX_REFERENCE_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_status
ovx_QueryReference (vx_reference ref, vx_enum attribute, void *ptr,
                    vx_size size);

#endif /* _OVX_REFERENCE_H */
