#ifndef _OVX_ARRAY_H
#define _OVX_ARRAY_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_status
ovx_AccessArrayRange (vx_array arr, vx_size start, vx_size end, vx_size *stride,
                      void **ptr, vx_enum usage);

extern vx_status
ovx_AddArrayItems (vx_array arr, vx_size count, void *ptr, vx_size stride);

extern vx_status
ovx_CommitArrayRange (vx_array arr, vx_size start, vx_size end, void *ptr);

extern vx_array
ovx_CreateArray (vx_context context, vx_enum item_type, vx_size capacity);

extern vx_array
ovx_CreateVirtualArray (vx_graph graph, vx_enum item_type, vx_size capacity);

extern vx_status
ovx_QueryArray (vx_array arr, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseArray (vx_array *arr);

extern vx_status
ovx_TruncateArray (vx_array arr, vx_size new_num_items);

#endif /* _OVX_ARRAY_H */
