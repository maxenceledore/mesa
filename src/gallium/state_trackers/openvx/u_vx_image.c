

#include "u_vx_image.h"
#include "ovx_types.h"

static enum pipe_format vx_format_to_pipe(vx_df_image format)
{
   switch(format) {
   case VX_DF_IMAGE_VIRT:
      return PIPE_FORMAT_B5G6R5_UNORM;
   case VX_DF_IMAGE_RGB:
      return PIPE_FORMAT_R10G10B10A2_SNORM;
   case VX_DF_IMAGE_RGBX:
      return PIPE_FORMAT_R8G8B8A8_UNORM;
   case VX_DF_IMAGE_NV12:
      return PIPE_FORMAT_NV12;
   case VX_DF_IMAGE_NV21:
      return PIPE_FORMAT_NV21;
   case VX_DF_IMAGE_UYVY:
      return PIPE_FORMAT_UYVY;
   case VX_DF_IMAGE_YUYV:
      return PIPE_FORMAT_YUYV;
   case VX_DF_IMAGE_IYUV:
      return PIPE_FORMAT_IYUV;
   case VX_DF_IMAGE_U8:
      return PIPE_FORMAT_R8_UINT;
   case VX_DF_IMAGE_U16:
      return PIPE_FORMAT_R16_UINT;
   case VX_DF_IMAGE_S16:
      return PIPE_FORMAT_R16_SINT;
   case VX_DF_IMAGE_U32:
      return PIPE_FORMAT_R32_UINT;
   case VX_DF_IMAGE_S32:
      return PIPE_FORMAT_R32_SINT;
   case VX_DF_IMAGE_YUV4: /* unavaible in gallium. TODO: correct this. */
   default:
      return PIPE_FORMAT_B8G8R8A8_UNORM;
   }
}
