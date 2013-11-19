
#include "VX/vx.h"

extern vx_status
ovx_AccessScalarValue (vx_scalar ref, void *ptr);

extern vx_status
ovx_CommitScalarValue (vx_scalar ref, void *ptr);

extern vx_scalar
ovx_CreateScalar (vx_context context, vx_enum data_type, void *ptr);

extern vx_status
vxQueryScalar (vx_scalar scalar, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseScalar (vx_scalar *scalar);
