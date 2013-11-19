#ifndef _OVX_CONVOLUTION_H
#define _OVX_CONVOLUTION_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_status
ovx_AccessConvolutionCoefficients (vx_convolution conv, vx_int16 *array);

extern vx_status
ovx_CommitConvolutionCoefficients (vx_convolution conv, vx_int16 *array);

extern vx_convolution
ovx_CreateConvolution (vx_context context, vx_size columns, vx_size rows);

extern vx_status
ovx_QueryConvolution (vx_convolution conv, vx_enum attribute, void *ptr,
                    vx_size size);

extern vx_status
ovx_ReleaseConvolution (vx_convolution *conv);

extern vx_status
ovx_SetConvolutionAttribute (vx_convolution conv, vx_enum attribute, void *ptr,
                           vx_size size);

#endif /* _OVX_CONVOLUTION_H */
