
#include "ovx_threshold.h"


vx_threshold
ovx_CreateThreshold (vx_context c, vx_enum thresh_type, vx_enum data_type)
{
  vx_threshold t;

  return t;
}


vx_status
ovx_QueryThreshold (vx_threshold thresh, vx_enum attribute, void *ptr,
                    vx_size size)
{
  return VX_SUCCESS;
}


vx_status
ovx_ReleaseThreshold (vx_threshold *thresh)
{
  return VX_SUCCESS;
}


vx_status
ovx_SetThresholdAttribute (vx_threshold thresh, vx_enum attribute, void *ptr,
                           vx_size size)
{
  return VX_SUCCESS;
}
