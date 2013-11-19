
#include "ovx_context.h"
#include "ovx_image.h"
#include "malloc.h"

vx_bool
is_valid_image (vx_image image)
{
  return vx_true_e;
}


vx_image
ovx_CreateImage (vx_context context, vx_uint32 width, vx_uint32 height,
                 vx_df_image color)
{
  vx_image img = malloc(sizeof(vx_image));

  /* specs : "Not guaranteed to exist until the vx_graph containing
   * it has been verified." 
   * TODO : Make it contained by a graph and verified when implemented.
   */

  if(img) {
    /* move it to a init_image function */
    img->width = width;
    img->height = height;
    img->format = color;
    /* TODO: gallium side init ... */
  }

  return img;
}

vx_image
ovx_CreateImageFromROI (vx_image img, vx_rectangle_t *rect)
{
  return NULL;
}

vx_image
ovx_CreateUniformImage (vx_context context, vx_uint32 width, vx_uint32 height,
                        vx_df_image color, void *value)
{
  if(is_valid_context(context) != vx_true_e)
    return NULL;

  return NULL;
}

vx_image
ovx_CreateVirtualImage (vx_graph graph, vx_uint32 width, vx_uint32 height,
                        vx_df_image color)
{
  return NULL;
}


vx_image
ovx_CreateImageFromHandle (vx_context context, vx_df_image color,
                           vx_imagepatch_addressing_t *addrs,
                           void **ptrs, vx_enum import_type)
{
  return NULL;
}



vx_status
ovx_QueryImage (vx_image image, vx_enum attribute, void *ptr, vx_size size)
{
  if(is_valid_image(image) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

  switch (attribute) {

    case VX_IMAGE_ATTRIBUTE_WIDTH:
      memcpy(ptr, &image->width, sizeof(image->width));
      break;
    case VX_IMAGE_ATTRIBUTE_HEIGHT:
      memcpy(ptr, &image->height, sizeof(image->height));
      break;
    case VX_IMAGE_ATTRIBUTE_FORMAT:
      memcpy(ptr, &image->format, sizeof(image->format));
      break;
    case VX_IMAGE_ATTRIBUTE_PLANES:
      memcpy(ptr, &image->planes, sizeof(image->planes));
      break;
    case VX_IMAGE_ATTRIBUTE_SPACE:
      memcpy(ptr, &image->color_space, sizeof(image->color_space));
      break;
    case VX_IMAGE_ATTRIBUTE_RANGE:
      memcpy(ptr, &image->channel_range, sizeof(image->channel_range));
      break;
    case VX_IMAGE_ATTRIBUTE_SIZE:
      memcpy(ptr, &image->size, sizeof(image->size));
      break;
    default:
      return VX_ERROR_INVALID_PARAMETERS;
  }

  return VX_SUCCESS;
}


vx_status
ovx_SetImageAttribute (vx_image image, vx_enum attribute, void *out, vx_size size)
{
  if(is_valid_image(image) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

  switch (attribute) {

    case VX_IMAGE_ATTRIBUTE_WIDTH:
      memcpy(&image->width, out, sizeof(image->width));
      break;
    case VX_IMAGE_ATTRIBUTE_HEIGHT:
      memcpy(&image->height, out, sizeof(image->height));
      break;
    case VX_IMAGE_ATTRIBUTE_FORMAT:
      memcpy(&image->format, out, sizeof(image->format));
      break;
    case VX_IMAGE_ATTRIBUTE_PLANES:
      memcpy(&image->planes, out, sizeof(image->planes));
      break;
    case VX_IMAGE_ATTRIBUTE_SPACE:
      memcpy(&image->color_space, out, sizeof(image->color_space));
      break;
    case VX_IMAGE_ATTRIBUTE_RANGE:
      memcpy(&image->channel_range, out, sizeof(image->channel_range));
      break;
    case VX_IMAGE_ATTRIBUTE_SIZE:
      memcpy(&image->size, out, sizeof(image->size));
      break;
    default:
      return VX_ERROR_INVALID_PARAMETERS;
  }

  return VX_SUCCESS;
}


vx_status
ovx_ReleaseImage (vx_image *image)
{
#if 0
  /* VX_ERROR_INVALID_REFERENCE	If graph is not a vx_graph. */

  image->refCount--;
#endif
  return VX_SUCCESS;
}


vx_size
ovx_ComputeImagePatchSize (vx_image image, vx_rectangle_t *rect,
                           vx_uint32 plane_index)
{
  return 0;
}

vx_status
ovx_AccessImagePatch (vx_image image, vx_rectangle_t *rect,
                      vx_uint32 plane_index, vx_imagepatch_addressing_t *addr,
                      void **ptr, vx_enum usage)
{
  return VX_SUCCESS;
}


vx_status
ovx_CommitImagePatch (vx_image image, vx_rectangle_t *rect,
                      vx_uint32 plane_index, vx_imagepatch_addressing_t *addr,
                      void *ptr)
{
  return VX_SUCCESS;
}


void *
ovx_FormatImagePatchAddress1d (void *ptr, vx_uint32 index,
                               vx_imagepatch_addressing_t *addr)
{
  return NULL;
}


void *
ovx_FormatImagePatchAddress2d (void *ptr, vx_uint32 x, vx_uint32 y,
                               vx_imagepatch_addressing_t *addr)
{
  return NULL;
}


vx_status
ovx_GetValidRegionImage (vx_image image, vx_rectangle_t *rect)
{
  return VX_SUCCESS;
}
