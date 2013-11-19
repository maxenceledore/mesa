
#include <stdio.h>

#include "ovx_defines.h"
#include "ovx_context.h"
#include "u_vx_log.h"

static const vx_char*
u_error_enum_to_string(vx_enum error);

static const vx_char*
u_error_enum_to_string(vx_enum error)
{
  switch (error) {
    case VX_STATUS_MIN:
      return "VX_STATUS_MIN";
    case VX_ERROR_REFERENCE_NONZERO:
      return "VX_ERROR_REFERENCE_NONZERO";
    case VX_ERROR_MULTIPLE_WRITERS:
      return "VX_ERROR_MULTIPLE_WRITERS";
    case VX_ERROR_GRAPH_ABANDONED:
      return "VX_ERROR_GRAPH_ABANDONED";
    case VX_ERROR_GRAPH_SCHEDULED:
      return "VX_ERROR_GRAPH_SCHEDULED";
    case VX_ERROR_INVALID_SCOPE:
      return "VX_ERROR_INVALID_SCOPE";
    case VX_ERROR_INVALID_NODE:
      return "VX_ERROR_INVALID_NODE";
    case VX_ERROR_INVALID_GRAPH:
      return "VX_ERROR_INVALID_GRAPH";
    case VX_ERROR_INVALID_TYPE:
      return "VX_ERROR_INVALID_TYPE";
    case VX_ERROR_INVALID_VALUE:
      return "VX_ERROR_INVALID_VALUE";
    case VX_ERROR_INVALID_DIMENSION:
      return "VX_ERROR_INVALID_DIMENSION";
    case VX_ERROR_INVALID_FORMAT:
      return "VX_ERROR_INVALID_FORMAT";
    case VX_ERROR_INVALID_LINK:
      return "VX_ERROR_INVALID_LINK";
    case VX_ERROR_INVALID_REFERENCE:
      return "VX_ERROR_INVALID_REFERENCE";
    case VX_ERROR_INVALID_MODULE:
      return "VX_ERROR_INVALID_MODULE";
    case VX_ERROR_INVALID_PARAMETERS:
      return "VX_ERROR_INVALID_PARAMETERS";
    case VX_ERROR_OPTIMIZED_AWAY:
      return "VX_ERROR_OPTIMIZED_AWAY";
    case VX_ERROR_NO_MEMORY:
      return "VX_ERROR_NO_MEMORY";
    case VX_ERROR_NO_RESOURCES:
      return "VX_ERROR_NO_RESOURCES";
    case VX_ERROR_NOT_COMPATIBLE:
      return "VX_ERROR_NOT_COMPATIBLE";
    case VX_ERROR_NOT_ALLOCATED:
      return "VX_ERROR_NOT_ALLOCATED";
    case VX_ERROR_NOT_SUFFICIENT:
      return "VX_ERROR_NOT_SUFFICIENT";
    case VX_ERROR_NOT_SUPPORTED:
      return "VX_ERROR_NOT_SUPPORTED";
    case VX_ERROR_NOT_IMPLEMENTED:
      return "VX_ERROR_NOT_IMPLEMENTED";
    case VX_FAILURE:
      return "VX_ERROR_NOT_IMPLEMENTED";
    case VX_SUCCESS:
      return "VX_SUCCESS";
    default:
      return NULL;
  }
}

void
u_log_message(vx_context context, vx_enum type, const vx_char *message)
{
  int32_t index = 0;
  const char* err_str = u_error_enum_to_string(type);

  if(is_valid_context(context) != vx_true_e)
    return;

  if(context->log_enabled != vx_true_e)
    return;

  if(context->log_msg_count / MAX_LOG_MESSAGE)
    index = context->log_msg_count % MAX_LOG_MESSAGE;

  snprintf(context->log[index], VX_MAX_LOG_MESSAGE_LEN, "%s : %s",
           err_str, message);

  context->log_msg_count++;
}
