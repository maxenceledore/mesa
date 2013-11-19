

#include "VX/vx.h"

extern vx_bool
is_graph(vx_graph graph);

extern vx_graph
ovx_CreateGraph (vx_context context);

extern vx_bool
ovx_IsGraphVerified (vx_graph graph);

extern vx_status
ovx_ProcessGraph (vx_graph graph);

extern vx_status
ovx_QueryGraph (vx_graph graph, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseGraph (vx_graph *graph);

extern vx_status
ovx_ScheduleGraph (vx_graph graph);

extern vx_status
ovx_SetGraphAttribute (vx_graph graph, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_VerifyGraph (vx_graph graph);

extern vx_status
ovx_WaitGraph (vx_graph graph);
