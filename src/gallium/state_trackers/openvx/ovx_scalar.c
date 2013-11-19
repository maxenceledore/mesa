
#include <string.h>

#include "VX/vx.h"
#include "u_vx_log.h"
#include "ovx_types.h"

vx_status
ovx_AccessScalarValue (vx_scalar ref, void *ptr)
{
  if(!ptr)
    return VX_ERROR_INVALID_PARAMETERS;

  /* XXX : correct this quickly */
  memcpy(ptr, ref->value.ui32, sizeof(vx_uint32));

  return VX_SUCCESS;
}


vx_status
ovx_CommitScalarValue (vx_scalar ref, void *ptr)
{
  if(!ptr)
    return VX_ERROR_INVALID_PARAMETERS;

  /* XXX : correct this quickly */
  memcpy(&ref->value.ui32, ptr, sizeof(vx_uint32));

  return VX_SUCCESS;
}


vx_scalar
ovx_CreateScalar (vx_context context, vx_enum data_type, void *ptr)
{
  vx_scalar s = NULL;

  if(data_type <= VX_TYPE_INVALID || data_type >= VX_TYPE_SCALAR_MAX) {
    u_log_message(context, VX_ERROR_INVALID_TYPE, "vxCreateScalar(data_type)");
    return s;
  }

  switch(data_type) {
    case VX_TYPE_CHAR:
    case VX_TYPE_INT8:
      memcpy(&s->value.i8, ptr, sizeof(vx_int8));
      break;
    case VX_TYPE_UINT8:
      memcpy(&s->valueui8, ptr, sizeof(vx_uint8));
      break;
    case VX_TYPE_INT16:
      memcpy(&s->valuei16, ptr, sizeof(vx_int16));
      break;
    case VX_TYPE_UINT16:
      memcpy(&s->valueui16, ptr, sizeof(vx_uint16));
      break;
    case VX_TYPE_INT32:
    case VX_TYPE_ENUM:
      memcpy(&s->valuei32, ptr, sizeof(vx_int32));
      break;
    case VX_TYPE_UINT32:
      memcpy(&s->valueui32, ptr, sizeof(vx_uint32));
      break;
    case VX_TYPE_INT64:
      memcpy(&s->valuei64, ptr, sizeof(vx_int64));
      break;
    case VX_TYPE_UINT64:
      memcpy(&s->valueui64, ptr, sizeof(vx_uint64));
      break;
    case VX_TYPE_FLOAT32:
      memcpy(&s->valuef32, ptr, sizeof(vx_float32));
      break;
    case VX_TYPE_FLOAT64:
      memcpy(&s->valuef64, ptr, sizeof(vx_float64));
      break;
    default:
      break;
  }

  return s;
}


vx_status
vxQueryScalar (vx_scalar scalar, vx_enum attribute, void *ptr, vx_size size)
{
  if(attribute == VX_SCALAR_ATTRIBUTE_TYPE) {
    (void) size;
    memcpy(ptr, &scalar->type, sizeof(vx_enum));
  }
  else
    return VX_ERROR_INVALID_VALUE;

  return VX_SUCCESS;
}


vx_status
ovx_ReleaseScalar (vx_scalar *scalar)
{
  return VX_SUCCESS;
}
