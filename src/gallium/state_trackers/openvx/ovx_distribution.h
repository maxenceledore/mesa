#ifndef _OVX_DISTRIBUTION_H
#define _OVX_DISTRIBUTION_H

#include "VX/vx.h"
#include "ovx_types.h"

extern vx_status
ovx_AccessDistribution (vx_distribution distribution, void **ptr, vx_enum usage);

extern vx_status
ovx_CommitDistribution (vx_distribution distribution, void *ptr);

extern vx_distribution
ovx_CreateDistribution (vx_context context, vx_size numBins, vx_size offset, vx_size range);

extern vx_status
ovx_QueryDistribution (vx_distribution distribution, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_ReleaseDistribution (vx_distribution *distribution);

#endif /* _OVX_DISTRIBUTION_H */
