#ifndef _OVX_NODE_H
#define _OVX_NODE_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_status
ovx_QueryNode (vx_node node, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseNode (vx_node *node);

extern void
ovx_RemoveNode (vx_node *node);

extern vx_status
ovx_SetNodeAttribute (vx_node node, vx_enum attribute, void *ptr, vx_size size);

#endif /* _OVX_NODE_H */