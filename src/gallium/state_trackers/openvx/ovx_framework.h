#ifndef _OVX_FRAMEWORK_H
#define _OVX_FRAMEWORK_H

#include <stdarg.h>
#include "VX/vx.h"


/*
 * Framework: Node Callbacks
 */
extern vx_status
ovx_AssignNodeCallback (vx_node node, vx_nodecomplete_f callback);

extern vx_nodecomplete_f
ovx_vxRetrieveNodeCallback (vx_node node);

/*
 * Framework: Log
 */
extern void
ovx_AddLogEntry (vx_reference ref, vx_status status, const char *message,...);

extern void
ovx_RegisterLogCallback (vx_context context, vx_log_callback_f callback,
                         vx_bool reentrant);

/*
 * Framework: Hint
 */
extern vx_status
ovx_Hint (vx_context context, vx_reference reference, vx_enum hint);

/*
 * Framework: Directives
 */
extern vx_status
ovx_Directive (vx_context context, vx_reference reference, vx_enum directive);

/*
 * Framework: User Kernels
 */
extern vx_kernel
ovx_AddKernel (vx_context context, vx_char name[VX_MAX_KERNEL_NAME],
               vx_enum enumeration, vx_kernel_f func_ptr,
               vx_uint32 numParams, vx_kernel_input_validate_f input,
               vx_kernel_output_validate_f output,
               vx_kernel_initialize_f init, vx_kernel_deinitialize_f deinit);

extern vx_status
ovx_AddParameterToKernel (vx_kernel kernel, vx_uint32 index, vx_enum dir,
                        vx_enum data_type, vx_enum state);

extern vx_status
ovx_FinalizeKernel (vx_kernel kernel);

extern vx_status
ovx_LoadKernels (vx_context context, vx_char *module);

extern vx_status
ovx_RemoveKernel (vx_kernel kernel);

extern vx_status
ovx_SetKernelAttribute (vx_kernel kernel, vx_enum attribute, void *ptr,
                        vx_size size);

extern vx_status
ovx_SetMetaFormatAttribute (vx_meta_format meta, vx_enum attribute,
                            void *ptr, vx_size size);

/*
 * Framework: Graph Parameters
 */
extern vx_status
ovx_AddParameterToGraph (vx_graph graph, vx_parameter parameter);

extern vx_parameter
ovx_GetGraphParameterByIndex (vx_graph graph, vx_uint32 index);

extern vx_status
ovx_SetGraphParameterByIndex (vx_graph graph, vx_uint32 index, vx_reference value);


#endif /* _OVX_FRAMEWORK_H */
