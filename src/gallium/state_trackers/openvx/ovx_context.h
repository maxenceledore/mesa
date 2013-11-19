#ifndef _OVX_CONTEXT_H
#define _OVX_CONTEXT_H

#include "VX/vx.h"

extern vx_enum
is_valid_context(vx_context context);

extern vx_enum
init_context(vx_context context);

extern vx_context
ovx_CreateContext (void);

extern vx_context
ovx_GetContext (vx_reference reference);

extern vx_status
ovx_GetStatus (vx_reference reference);

extern vx_status
ovx_QueryContext (vx_context context, vx_enum attr, void * ptr, vx_size size);

extern void
ovx_ReleaseContext (vx_context * context);

extern vx_status
ovx_SetContextAttribute (vx_context context, vx_enum attribute, void *ptr,
                         vx_size size);

extern vx_enum
ovx_RegisterUserStruct (vx_context context, vx_size size);

#endif /* _OVX_CONTEXT_H */
