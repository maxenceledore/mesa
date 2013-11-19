#ifndef _OVX_KERNEL_H
#define _OVX_KERNEL_H

#include "VX/vx.h"
#include "ovx_types.h"


extern vx_kernel
ovx_GetKernelByEnum(vx_context context, vx_enum kernel);

extern vx_kernel
ovx_GetKernelByName (vx_context context, vx_char *name);



extern const vx_kernel*
init_kernels (void);

#endif /* _OVX_KERNEL_H */