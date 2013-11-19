#ifndef _OVX_TYPES_H
#define _OVX_TYPES_H

#include "VX/vx.h"

#include "ovx_defines.h"

struct mapi_table;

typedef struct _vx_array {

  vx_enum       item_type;
  vx_size       num_items;
  vx_size       capacity;
  vx_size       itemsize;

  vx_uint32     refCount;
} *vx_array;

typedef struct _vx_context {

   struct mapi_table *dispatch;

   struct pipe_context *pipe;

   vx_uint16         vendorID;
   vx_uint16         major_version;
   vx_uint16         minor_version;
   vx_char           implementationName[VX_MAX_IMPLEMENTATION_NAME];

   vx_bool           log_enabled;
   vx_log_callback_f log_callback_func;
   vx_char           log[MAX_LOG_MESSAGE][VX_MAX_LOG_MESSAGE_LEN];
   vx_int32          log_msg_count;

   vx_bool           parallelization_enabled;

   vx_kernel        *avaible_kernels;

   vx_uint32         activeKernels;
   vx_uint32         activeModules;
   vx_uint32         activeTargets;

   vx_size           extensionSize;
   vx_char          *extensions;

   vx_reference refCount;
} *vx_context;


typedef struct _vx_convolution {

  vx_size       rows;
  vx_size       columns;
  vx_size       scale;
  vx_uint32     size;

  vx_uint32     refCount;
} *vx_convolution;


typedef struct _vx_distribution {

  vx_size       rows;
  vx_size       columns;
  vx_size       scale;
  vx_uint32     size;

  vx_uint32     refCount;
} *vx_distribution;


typedef struct _vx_graph {

  vx_uint32       num_nodes;
  vx_status       overall_status;
  vx_perf_t       overall_perf;
  vx_uint32       explicitly_declared_params;

  vx_bool         verified;
  vx_bool         exec_completed;

  vx_uint32       refCount;
} *vx_graph;


typedef struct _vx_image {

   vx_uint32      width;
   vx_uint32      height;
   vx_df_image    format;
   vx_size        planes;
   vx_enum        color_space;
   vx_enum        channel_range;
   vx_size        size;

   vx_uint32      refCount;
} *vx_image;


typedef struct _vx_kernel {

  vx_enum         kernel_id;
  vx_char         kernel_name[VX_MAX_KERNEL_NAME];

  _vx_kernel_info_t kernel_info;

  vx_uint32       refCount;
} *vx_kernel;


typedef struct _vx_lut {

  vx_enum      type;
  vx_size      count;
  vx_size      size;

  void        *lut;

  vx_reference refCount;
} *vx_lut;


typedef struct _vx_matrix {

  vx_enum      type;
  vx_size      size;

  union { vx_float32  *f32;
          vx_int32    *i32;
  } mat;

  vx_size      columns;
  vx_size      rows;

  vx_reference refCount;
} *vx_matrix;


typedef struct _vx_node {

  vx_status        status;
  vx_perf_t        performance;
  vx_border_mode_t border_mode;
  vx_size          local_data_size;

  vx_reference     refCount;
} *vx_node;


typedef struct _vx_pyramid {

  vx_size      levels;
  vx_float32   scale;
  vx_uint32    width;
  vx_uint32    height;
  vx_df_image  format;

  vx_bool      is_virtual;

  vx_reference refCount;
} *vx_pyramid;


typedef struct _vx_reference {

  vx_uint32     count;
  vx_enum       type;
} *vx_reference;


typedef struct _vx_scalar {

  vx_enum      type;

  union {
    vx_int8      i8;
    vx_uint8     ui8;
    vx_int16     i16;
    vx_uint16    ui16;
    vx_int32     i32;
    vx_uint32    ui32;
    vx_int64     i64;
    vx_uint64    ui64;
    vx_float32   f32;
    vx_float64   f64;
  } value;

  vx_reference refCount;
} *vx_scalar;


typedef struct _vx_threshold {

  vx_enum      type;
  vx_int32     value;
  vx_int32     lower;
  vx_int32     upper;
  vx_int32     true_val;
  vx_int32     false_val;

  vx_reference refCount;
} *vx_threshold;


#endif /* _OVX_TYPES_H */
