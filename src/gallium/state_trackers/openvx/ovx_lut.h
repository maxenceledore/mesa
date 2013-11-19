#ifndef _OVX_LUT_H
#define _OVX_LUT_H

#include "VX/vx.h"

extern vx_status
ovx_AccessLUT (vx_lut lut, void **ptr, vx_enum usage);

extern vx_status
ovx_CommitLUT (vx_lut lut, void *ptr);

extern vx_lut
ovx_CreateLUT (vx_context context, vx_enum data_type, vx_size count);


extern vx_status
ovx_QueryLUT (vx_lut lut, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseLUT (vx_lut *lut);

#endif /* _OVX_LUT_H */
