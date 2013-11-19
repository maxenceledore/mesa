

#include "ovx_convolution.h"


vx_status
ovx_AccessConvolutionCoefficients (vx_convolution conv, vx_int16 *array)
{
  return VX_SUCCESS;
}


vx_status
ovx_CommitConvolutionCoefficients (vx_convolution conv, vx_int16 *array)
{
  return VX_SUCCESS;
}


vx_convolution
ovx_CreateConvolution (vx_context context, vx_size columns, vx_size rows)
{
  return VX_SUCCESS;
}


vx_status
ovx_QueryConvolution (vx_convolution conv, vx_enum attribute, void *ptr,
                    vx_size size)
{
  return VX_SUCCESS;
}


vx_status
vxReleaseConvolution (vx_convolution *conv)

vx_status
ovx_SetConvolutionAttribute (vx_convolution conv, vx_enum attribute, void *ptr,
                           vx_size size)
{
  /* The scale of the convolution matrix,
   * For 1.0, only powers of 2 are supported up to 2^31.
   */

  return VX_SUCCESS;
}
