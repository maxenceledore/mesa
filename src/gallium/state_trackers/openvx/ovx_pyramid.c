
#include "ovx_types.h"
#include "ovx_image.h"
#include "u_vx_log.h"

vx_pyramid
ovx_CreatePyramid (vx_context context, vx_size levels, vx_float32 scale,
                   vx_uint32 width, vx_uint32 height, vx_df_image format)
{
  vx_pyramid p = NULL;

  p->levels = levels;
  p->width = width;
  p->height = height;
  p->format = format;

  if(scale == VX_SCALE_PYRAMID_HALF || scale == VX_SCALE_PYRAMID_ORB)
    /* only half is supported for now */
    p->scale = VX_SCALE_PYRAMID_HALF;
  else
    

  return p;
}


vx_pyramid
ovx_CreateVirtualPyramid (vx_graph graph, vx_size levels, vx_float32 scale,
                          vx_uint32 width, vx_uint32 height,
                          vx_df_image format)
{
  vx_pyramid p = NULL;

  p->levels = levels;
  p->width = width;
  p->height = height;
  p->format = format;

  if(scale == VX_SCALE_PYRAMID_HALF || scale == VX_SCALE_PYRAMID_ORB)
    /* only half is supported for now */
    p->scale = VX_SCALE_PYRAMID_HALF;

  p->is_virtual = vx_true_e;

  return p;
}


vx_image
ovx_GetPyramidLevel (vx_pyramid pyr, vx_uint32 index)
{
  vx_image i = NULL;

  index;

  return i;
}


vx_status
ovx_QueryPyramid (vx_pyramid pyr, vx_enum attribute, void *ptr, vx_size size)
{
  attribute;
  ptr;
  size;

  return VX_SUCCESS;
}


vx_status
ovx_ReleasePyramid (vx_pyramid *pyr)
{
  pyr;

  return VX_SUCCESS;
}
