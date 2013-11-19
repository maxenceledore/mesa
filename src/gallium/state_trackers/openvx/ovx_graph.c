

#include "ovx_context.h"
#include "ovx_graph.h"
#include "ovx_node.h"
#include "ovx_types.h"

vx_bool
is_graph(vx_graph *graph)
{
  return vx_true_e;
}


vx_graph
ovx_CreateGraph (vx_context context)
{
  if(is_valid_context(context) != vx_true_e)
    return NULL;

  return VX_SUCCESS;
}


vx_bool
ovx_IsGraphVerified (vx_graph graph)
{
  if(graph->verified == vx_true_e)
    return vx_true_e;
  else
    return vx_false_e;
}


vx_status
ovx_ProcessGraph (vx_graph graph)
{
  vx_status err = VX_SUCCESS;

  if(graph->verified != vx_true_e)
    err = ovx_VerifyGraph(graph);

  if(err != VX_SUCCESS)
    return VX_ERROR_NOT_SUFFICIENT;

  /*
   * TODO: implement a Scheduler for each context.
   */

  return VX_SUCCESS;
}


vx_status
ovx_QueryGraph (vx_graph graph, vx_enum attribute, void *ptr, vx_size size)
{
  if(is_graph(graph) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

  switch (attribute) {

    case VX_GRAPH_ATTRIBUTE_NUMNODES:
      memcpy(ptr, &graph->num_nodes, sizeof(graph->num_nodes));
      break;
    case VX_GRAPH_ATTRIBUTE_STATUS:
      memcpy(ptr, &graph->overall_status, sizeof(graph->overall_status));
      break;
    case VX_GRAPH_ATTRIBUTE_PERFORMANCE:
      memcpy(ptr, &graph->overall_perf, sizeof(graph->overall_perf));
      break;
    case VX_GRAPH_ATTRIBUTE_NUMPARAMETERS:
      memcpy(ptr, &graph->explicitly_declared_params,
             sizeof(graph->explicitly_declared_params));
      break;
    default:
      return VX_ERROR_INVALID_PARAMETERS;
  }

  return VX_SUCCESS;
}


vx_status
ovx_ReleaseGraph (vx_graph *graph)
{
  if(is_graph(*graph) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

/* Releases a reference to a graph. The object may not be garbage collected
 * until its total reference count is zero. Once the reference count is zero,
 * all node references in the graph are automatically released as well. Data
 * referenced by those nodes may not be released as the user may have
 * external references to the data.
 */
  graph->refCount--;
  if(!graph->refCount)
    /* release node (but not necessary associated data) */
    ;

  return VX_SUCCESS;
}


vx_status
ovx_ScheduleGraph (vx_graph graph)
{
  vx_status err = VX_SUCCESS;

  if(graph->verified != vx_true_e)
    err = ovx_VerifyGraph(graph);

  if(err != VX_SUCCESS)
    return VX_ERROR_NOT_SUFFICIENT;

  return VX_SUCCESS;
}


vx_status
ovx_SetGraphAttribute (vx_graph graph, vx_enum attribute, void *ptr, vx_size size)
{
  if(is_graph(graph) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

  switch (attribute) {

    case VX_GRAPH_ATTRIBUTE_NUMNODES:
      memcpy(&graph->num_nodes, ptr, sizeof(graph->num_nodes));
      break;
    case VX_GRAPH_ATTRIBUTE_STATUS:
      memcpy(&graph->overall_status, ptr, sizeof(graph->overall_status));
      break;
    case VX_GRAPH_ATTRIBUTE_PERFORMANCE:
      memcpy(&graph->overall_perf, ptr, sizeof(graph->overall_perf));
      break;
    case VX_GRAPH_ATTRIBUTE_NUMPARAMETERS:
      memcpy(&graph->explicitly_declared_params, ptr,
             sizeof(graph->explicitly_declared_params));
      break;
    default:
      return VX_ERROR_INVALID_PARAMETERS;
  }

  return VX_SUCCESS;
}


vx_status
ovx_VerifyGraph (vx_graph graph)
{
  if(is_graph(graph) != vx_true_e)
    return VX_ERROR_INVALID_REFERENCE;

/*  TODO:
 *  VX_ERROR_MULTIPLE_WRITERS	If the graph contains more than one writer to any data object.
 *  VX_ERROR_INVALID_NODE	If a node in the graph is invalid or failed be created.
 *  VX_ERROR_INVALID_GRAPH	If the graph contains cycles or some other invalid topology.
 *  VX_ERROR_INVALID_TYPE	If any parameter on a node is given the wrong type.
 *  VX_ERROR_INVALID_VALUE	If any value of any parameter is out of bounds of specification.
 *  VX_ERROR_INVALID_FORMAT	If the image format is not compatible.
 */
  return VX_SUCCESS;
}


vx_status
ovx_WaitGraph (vx_graph graph)
{
  if(is_graph(graph) != vx_true_e)
    return VX_FAILURE;

  if(graph->exec_completed == vx_true_e)
    return VX_SUCCESS;
  else
    return VX_FAILURE;
}
