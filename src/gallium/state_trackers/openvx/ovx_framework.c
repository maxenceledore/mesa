


#include "ovx_context.h"
#include "ovx_framework.h"

#include "u_vx_log.h"


/*
 * Framework: Node Callbacks
 */
vx_status
ovx_AssignNodeCallback (vx_node node, vx_nodecomplete_f callback)
{
  return VX_SUCCESS;
}

vx_nodecomplete_f
ovx_vxRetrieveNodeCallback (vx_node node)
{
  return NULL;
}

/*
 * Framework: Log
 */
void
ovx_AddLogEntry (vx_reference ref, vx_status status, const char *message,...)
{
  (void)(ref);
  (void)(status);
  (void)(message);
  return;
}

void
ovx_RegisterLogCallback (vx_context context, vx_log_callback_f callback,
                         vx_bool reentrant)
{
  if(is_valid_context(context) != vx_true_e)
    return;

  context->log_callback_func = callback;

  /* TODO: no thread-safe policy for the moment.
   * Just ignores reentrance parameter. */
  (void)(reentrant);
}



/*
 * Framework: Hint
 */
vx_status
ovx_Hint (vx_context context, vx_reference reference, vx_enum hint)
{
  if(is_valid_context(context) != vx_true_e) {
    u_log_message(context, VX_ERROR_INVALID_REFERENCE, "from vxHint");
    return VX_ERROR_INVALID_REFERENCE;
  }

  switch (hint) {
    case VX_HINT_SERIALIZE:
      context->parallelization_enabled = vx_true_e;
      return VX_SUCCESS;
    default:
      u_log_message(context, VX_ERROR_NOT_SUPPORTED, "from vxHint");
      return VX_ERROR_NOT_SUPPORTED;
  }
}

/*
 * Framework: Directives
 */
vx_status
ovx_Directive (vx_context context, vx_reference reference, vx_enum directive)
{
  if(is_valid_context(context) != vx_true_e) {
    u_log_message(context, VX_ERROR_INVALID_REFERENCE, "from Directive");
    return VX_ERROR_INVALID_REFERENCE;
  }

  switch (directive) {
    case VX_DIRECTIVE_DISABLE_LOGGING:
      context->log_enabled = vx_false_e;
      return VX_SUCCESS;
    case VX_DIRECTIVE_ENABLE_LOGGING:
      context->log_enabled = vx_true_e;
      return VX_SUCCESS;
    default:
      u_log_message(context, VX_ERROR_NOT_SUPPORTED, "from Directive");
      return VX_ERROR_NOT_SUPPORTED;
  }
}

/*
 * Framework: User Kernels
 */
vx_kernel
ovx_AddKernel (vx_context context, vx_char name[VX_MAX_KERNEL_NAME],
               vx_enum enumeration, vx_kernel_f func_ptr,
               vx_uint32 numParams, vx_kernel_input_validate_f input,
               vx_kernel_output_validate_f output,
               vx_kernel_initialize_f init, vx_kernel_deinitialize_f deinit)
{
  return NULL;
}

vx_status
ovx_AddParameterToKernel (vx_kernel kernel, vx_uint32 index, vx_enum dir,
                        vx_enum data_type, vx_enum state)
{
  return VX_SUCCESS;
}

vx_status
ovx_FinalizeKernel (vx_kernel kernel)
{
  return VX_SUCCESS;
}

vx_status
ovx_LoadKernels (vx_context context, vx_char *module)
{
  return VX_SUCCESS;
}

vx_status
ovx_RemoveKernel (vx_kernel kernel)
{
  return VX_SUCCESS;
}

vx_status
ovx_SetKernelAttribute (vx_kernel kernel, vx_enum attribute, void *ptr,
                        vx_size size)
{
  return VX_SUCCESS;
}

vx_status
ovx_SetMetaFormatAttribute (vx_meta_format meta, vx_enum attribute,
                            void *ptr, vx_size size)
{
  return VX_SUCCESS;
}

/*
 * Framework: Graph Parameters
 */
vx_status
ovx_AddParameterToGraph (vx_graph graph, vx_parameter parameter)
{
  return VX_SUCCESS;
}

vx_parameter
ovx_GetGraphParameterByIndex (vx_graph graph, vx_uint32 index)
{
  return VX_SUCCESS;
}

vx_status
ovx_SetGraphParameterByIndex (vx_graph graph, vx_uint32 index, vx_reference value)
{
  return VX_SUCCESS;
}
