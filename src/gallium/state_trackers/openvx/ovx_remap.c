

#include "ovx_remap.h"

vx_remap
ovx_CreateRemap (vx_context context, vx_uint32 src_width,
                 vx_uint32 src_height, vx_uint32 dst_width,
                 vx_uint32 dst_height)
{
  vx_remap rm = NULL;

  return rm;
}


vx_status
ovx_GetRemapPoint (vx_remap table, vx_uint32 dst_x, vx_uint32 dst_y,
                   vx_float32 *src_x, vx_float32 *src_y)
{
  return VX_SUCCESS;
}


vx_status
ovx_QueryRemap (vx_remap r, vx_enum attribute, void *ptr, vx_size size)
{
  return VX_SUCCESS;
}


vx_status
ovx_ReleaseRemap (vx_remap *table)
{
  return VX_SUCCESS;
}


vx_status
ovx_SetRemapPoint (vx_remap table, vx_uint32 dst_x, vx_uint32 dst_y,
                   vx_float32 src_x, vx_float32 src_y)
{
  return VX_SUCCESS;
}
