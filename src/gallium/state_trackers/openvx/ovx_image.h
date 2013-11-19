#ifndef _OVX_IMAGE_H
#define _OVX_IMAGE_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_bool
is_valid_image (vx_image image);

extern vx_image
ovx_CreateImage (vx_context context, vx_uint32 width, vx_uint32 height,
                 vx_df_image color);

extern vx_image
ovx_CreateImageFromROI (vx_image img, vx_rectangle_t *rect);

extern vx_image
ovx_CreateUniformImage (vx_context context, vx_uint32 width, vx_uint32 height,
                      vx_df_image color, void *value);

extern vx_image
ovx_CreateVirtualImage (vx_graph graph, vx_uint32 width, vx_uint32 height,
                      vx_df_image color);

extern vx_image
ovx_CreateImageFromHandle (vx_context context, vx_df_image color,
                           vx_imagepatch_addressing_t *addrs,
                           void **ptrs, vx_enum import_type);

extern vx_status
ovx_QueryImage (vx_image image, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_SetImageAttribute (vx_image image, vx_enum attribute, void *out, vx_size size);

extern vx_status
ovx_ReleaseImage (vx_image *image);

extern vx_size
ovx_ComputeImagePatchSize (vx_image image, vx_rectangle_t *rect,
                           vx_uint32 plane_index);

extern vx_status
ovx_AccessImagePatch (vx_image image, vx_rectangle_t *rect,
                      vx_uint32 plane_index, vx_imagepatch_addressing_t *addr,
                      void **ptr, vx_enum usage);



extern vx_status
ovx_CommitImagePatch (vx_image image, vx_rectangle_t *rect,
                      vx_uint32 plane_index, vx_imagepatch_addressing_t *addr,
                      void *ptr);


extern void *
ovx_FormatImagePatchAddress1d (void *ptr, vx_uint32 index,
                             vx_imagepatch_addressing_t *addr);


extern void *
ovx_FormatImagePatchAddress2d (void *ptr, vx_uint32 x, vx_uint32 y,
                             vx_imagepatch_addressing_t *addr);

extern vx_status
ovx_GetValidRegionImage (vx_image image, vx_rectangle_t *rect);

#endif /* _OVX_IMAGE_H */