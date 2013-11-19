
#include "ovx_array.h"

vx_status
ovx_AccessArrayRange (vx_array arr, vx_size start, vx_size end, vx_size *stride,
                      void **ptr, vx_enum usage)
{
  return VX_SUCCESS;
}


vx_status
ovx_AddArrayItems (vx_array arr, vx_size count, void *ptr, vx_size stride)
{
  return VX_SUCCESS;
}


vx_status
ovx_CommitArrayRange (vx_array arr, vx_size start, vx_size end, void *ptr)
{
  return VX_SUCCESS;
}

vx_array
ovx_CreateArray (vx_context context, vx_enum item_type, vx_size capacity)
{
  vx_array a;

  return a;
}


vx_array
ovx_CreateVirtualArray (vx_graph graph, vx_enum item_type, vx_size capacity)
{
  vx_array a;

  return a;
}


vx_status
ovx_QueryArray (vx_array arr, vx_enum attribute, void *ptr, vx_size size)
{
  return VX_SUCCESS;
}


vx_status
ovx_ReleaseArray (vx_array *arr)
{
  return VX_SUCCESS;
}


vx_status
ovx_TruncateArray (vx_array arr, vx_size new_num_items)
{
  return VX_SUCCESS;
}
