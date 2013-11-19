#ifndef _OVX_THRESHOLD_H
#define _OVX_THRESHOLD_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_threshold
ovx_CreateThreshold (vx_context c, vx_enum thresh_type, vx_enum data_type);

extern vx_status
ovx_QueryThreshold (vx_threshold thresh, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseThreshold (vx_threshold *thresh);

extern vx_status
ovx_SetThresholdAttribute (vx_threshold thresh, vx_enum attribute, void *ptr, vx_size size);

#endif /* _OVX_THRESHOLD_H */
