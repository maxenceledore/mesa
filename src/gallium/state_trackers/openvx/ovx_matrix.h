#ifndef _OVX_MATRIX_H
#define _OVX_MATRIX_H

#include "VX/vx.h"

extern vx_matrix
ovx_CreateMatrix(vx_context c, vx_enum type, vx_size columns, vx_size rows);

extern vx_status
ovx_ReleaseMatrix(vx_matrix *mat);

extern vx_status
ovx_QueryMatrix(vx_matrix mat, vx_enum attribute, void *ptr, vx_size size);

extern vx_status
ovx_AccessMatrix (vx_matrix mat, void *array);

vx_status
ovx_CommitMatrix (vx_matrix mat, void *array);

#endif /* _OVX_MATRIX_H */