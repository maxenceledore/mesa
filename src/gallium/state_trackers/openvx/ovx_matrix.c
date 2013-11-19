

#include <malloc.h>
#include <string.h>

#include "ovx_matrix.h"
#include "ovx_types.h"
#include "u_vx_log.h"

vx_matrix
ovx_CreateMatrix(vx_context c, vx_enum type, vx_size columns, vx_size rows)
{
  vx_matrix m = NULL;

  if(type != VX_TYPE_INT32 && type != VX_TYPE_FLOAT32)
    u_log_message(c, VX_ERROR_INVALID_TYPE, "Invalid matrix data type");
    return NULL;

  m->columns = columns;
  m->rows = rows;
  m->type = type;
  m->size = columns*rows*sizeof(vx_float32);
  m->refCount = 1;

  m->mat.f32 = malloc (columns*rows*sizeof(vx_float32));

  return NULL;
}


extern vx_status
ovx_ReleaseMatrix(vx_matrix *mat)
{
  return VX_SUCCESS;
}

vx_status
ovx_QueryMatrix(vx_matrix mat, vx_enum attribute, void *ptr, vx_size size)
{
  /*TODO : check mat first */

  switch(attribute) {
    case VX_MATRIX_ATTRIBUTE_TYPE:
      if(ptr && size > 4)
        memcpy(ptr, &mat->type, 4);
        break;
    case VX_MATRIX_ATTRIBUTE_COLUMNS:
    if(ptr && size > 4)
        memcpy(ptr, &mat->columns, 4);
        break;
    case VX_MATRIX_ATTRIBUTE_ROWS:
    if(ptr && size > 4)
        memcpy(ptr, &mat->rows, 4);
        break;
    case VX_MATRIX_ATTRIBUTE_SIZE:
    if(ptr && size > 4)
        memcpy(ptr, &mat->size, 4);
        break;
    default:
      return VX_ERROR_NOT_SUPPORTED;
  }
  return VX_SUCCESS;
}


vx_status
ovx_AccessMatrix (vx_matrix mat, void *array)
{
  vx_matrix m = NULL;
  vx_int32 ncols, nrows;

  ncols = mat->columns;
  ncols = mat->rows;

  memcpy(array, m->mat.f32, mat->size);

  return VX_SUCCESS;
}


vx_status
ovx_CommitMatrix (vx_matrix mat, void *array)
{
  memcpy(mat->mat.f32, array, mat->size);

  return VX_SUCCESS;
}
