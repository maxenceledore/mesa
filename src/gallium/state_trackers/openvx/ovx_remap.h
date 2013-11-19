#ifndef _OVX_REMAP_H
#define _OVX_REMAP_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_remap
ovx_CreateRemap (vx_context context, vx_uint32 src_width,
                 vx_uint32 src_height, vx_uint32 dst_width,
                 vx_uint32 dst_height);

extern vx_status
ovx_GetRemapPoint (vx_remap table, vx_uint32 dst_x, vx_uint32 dst_y,
                   vx_float32 *src_x, vx_float32 *src_y);

extern vx_status
ovx_QueryRemap (vx_remap r, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseRemap (vx_remap *table);

extern vx_status
ovx_SetRemapPoint (vx_remap table, vx_uint32 dst_x, vx_uint32 dst_y,
                   vx_float32 src_x, vx_float32 src_y);

#endif /* _OVX_REMAP_H */
