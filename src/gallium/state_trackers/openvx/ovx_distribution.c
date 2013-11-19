
#include "ovx_distribution.h"

vx_status
ovx_AccessDistribution (vx_distribution distribution, void **ptr,
                        vx_enum usage)
{
  return VX_SUCCESS;
}


vx_status
ovx_CommitDistribution (vx_distribution distribution, void *ptr)
{
  return VX_SUCCESS;
}


vx_distribution
ovx_CreateDistribution (vx_context context, vx_size numBins, vx_size offset,
                        vx_size range)
{
  vx_distribution v = NULL;

  return v;
}


vx_status
ovx_QueryDistribution (vx_distribution distribution, vx_enum attribute,
                       void *ptr, vx_size size)
{
  return VX_SUCCESS;
}


vx_status
ovx_ReleaseDistribution (vx_distribution *distribution)
{
  return VX_SUCCESS;
}
