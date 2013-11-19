#ifndef _OVX_PYRAMID_H
#define _OVX_PYRAMID_H

#include "VX/vx.h"

extern vx_pyramid
ovx_CreatePyramid (vx_context context, vx_size levels, vx_float32 scale, vx_uint32 width, vx_uint32 height, vx_df_image format);

extern vx_pyramid
ovx_CreateVirtualPyramid (vx_graph graph, vx_size levels, vx_float32 scale, vx_uint32 width, vx_uint32 height, vx_df_image format);

extern vx_image
ovx_GetPyramidLevel (vx_pyramid pyr, vx_uint32 index);

extern vx_status
ovx_QueryPyramid (vx_pyramid pyr, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleasePyramid (vx_pyramid *pyr);

#endif /* _OVX_PYRAMID_H */
