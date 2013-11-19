
#include "ovx_types.h"
#include "ovx_node.h"

vx_status
ovx_QueryNode (vx_node node, vx_enum attribute, void *ptr, vx_size size)
{
  node->vx_status;
  node->performance;
  node->border_mode.constant_value;
  node->border_mode.mode;
  node->local_data_size;

  return VX_SUCCESS;
}

vx_status
ovx_ReleaseNode (vx_node *node)
{
  node;
  return VX_SUCCESS;
}

void
ovx_RemoveNode (vx_node *node)
{
  node;
  ovx_ReleaseNode (node);
  return;
}


vx_status
ovx_SetNodeAttribute (vx_node node, vx_enum attribute, void *ptr, vx_size size)
{
  return VX_SUCCESS;
}
