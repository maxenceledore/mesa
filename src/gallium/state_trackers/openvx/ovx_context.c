#include <malloc.h>
#include <string.h>

#include "VX/vx.h"
#include "ovx_context.h"
#include "ovx_kernel.h"
#include "ovx_types.h"


vx_enum
is_valid_context(vx_context context)
{
  return vx_true_e;
}

vx_enum
init_context(vx_context context)
{
  context->avaible_kernels = (vx_kernel*) init_kernels();

  return vx_true_e;
}

vx_context
ovx_CreateContext(void)
{
  vx_context c = malloc(sizeof(vx_context));

//c->released = vx_false_e;

  return c;
}


vx_context ovx_GetContext(vx_reference reference)
{
  return NULL;
}

vx_status
ovx_GetStatus (vx_reference reference)
{
  return VX_SUCCESS;
}


vx_status
ovx_QueryContext(vx_context context, vx_enum attr, void * ptr, vx_size size)
{
  if(!context)
    return VX_ERROR_INVALID_REFERENCE;

  switch(attr) {
    case VX_CONTEXT_ATTRIBUTE_VENDOR_ID:
      if(ptr && size >= sizeof(vx_uint16)) {
        memcpy(ptr, &context->vendorID, sizeof(vx_uint16));
        return VX_SUCCESS;
      }
    case VX_CONTEXT_ATTRIBUTE_VERSION:
      if(ptr && size >= sizeof(vx_uint16)) {
        memcpy(ptr, &context->major_version, sizeof(vx_uint16));
        return VX_SUCCESS;
      }
    case VX_CONTEXT_ATTRIBUTE_IMPLEMENTATION:
      return VX_ERROR_NOT_SUPPORTED;

    case VX_CONTEXT_ATTRIBUTE_EXTENSIONS_SIZE:
      if(ptr && size >= sizeof(vx_size)) {
        memcpy(ptr, &context->extensionSize, sizeof(vx_size));
        return VX_SUCCESS;
      }
    case VX_CONTEXT_ATTRIBUTE_EXTENSIONS:
      return VX_ERROR_NOT_SUPPORTED;

    case VX_CONTEXT_ATTRIBUTE_CONVOLUTION_MAXIMUM_DIMENSION:
      return VX_ERROR_NOT_SUPPORTED;

    default:
      return VX_ERROR_INVALID_PARAMETERS;
  }
}


void
ovx_ReleaseContext(vx_context * context)
{

/*  context->released = vx_true_e; */
  return;
}


vx_status
ovx_SetContextAttribute (vx_context context, vx_enum attribute, void *ptr,
                         vx_size size)
{
  return VX_SUCCESS;
}


vx_enum
ovx_RegisterUserStruct (vx_context context, vx_size size)
{
  return VX_SUCCESS;
}
