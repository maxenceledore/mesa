
#include <string.h>

#include "ovx_context.h"
#include "ovx_kernel.h"
#include "ovx_types.h"


static void init_invalid_kernel (void);
static void init_color_conversion_kernel (void);
static void init_generic_channel_extraction_kernel (void);
static void init_generic_channel_combine_kernel (void);
static void init_3x3_sobel_filter_kernel (void);
static void init_magnitude_kernel (void);
static void init_phase_kernel (void);
static void init_scale_image_kernel (void);
static void init_table_lookup_kernel (void);
static void init_histogram_kernel (void);
static void init_histogram_equalization_kernel (void);
static void init_absolute_difference_kernel (void);
static void init_mean_stddev_kernel (void);
// TODO: and lots of others ...


extern vx_kernel
ovx_GetKernelByEnum(vx_context context, vx_enum kernel)
{
  vx_kernel *kerns = NULL;
  int i = 0;

  if(is_valid_context(context) != vx_true_e)
    return NULL;
  else
    kerns = context->avaible_kernels;

  for(i = VX_KERNEL_INVALID ; i < VX_KERNEL_MAX_1_0 ; i++) {
    if(kernel == kerns[i]->kernel_id)
      return kerns[i];
  }
  return NULL;
}


extern vx_kernel
ovx_GetKernelByName (vx_context context, vx_char *name)
{
  vx_kernel *kerns = NULL;
  int i = 0;

  if(is_valid_context(context) != vx_true_e)
    return NULL;
  else
    kerns = context->avaible_kernels;

  for(i = VX_KERNEL_INVALID ; i < VX_KERNEL_MAX_1_0 ; i++) {
    if(strcmp(name, kerns[i]->kernel_name) == 0)
      return kerns[i];
  }
  return NULL;
}



extern const vx_kernel*
init_kernels (void)
{
  static vx_kernel avaible_kernels [VX_KERNEL_MAX_1_0];

  init_invalid_kernel ();
  init_color_conversion_kernel ();
  init_generic_channel_extraction_kernel ();
  init_generic_channel_combine_kernel ();
  init_3x3_sobel_filter_kernel ();
  init_magnitude_kernel ();
  init_phase_kernel ();
  init_scale_image_kernel ();
  init_table_lookup_kernel ();
  init_histogram_kernel ();
  init_histogram_equalization_kernel (  );
  init_absolute_difference_kernel ();
  init_mean_stddev_kernel ();

  return avaible_kernels;
}
#if 0
static void
init_invalid_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.invalid";
  vx_enum k_id = VX_KERNEL_INVALID;

  const char tgsi_fs_shader[] = ""; /* TODO */
}

static void
init_color_conversion_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.color_convert";
  vx_enum k_id = VX_KERNEL_COLOR_CONVERT;
}

static void
init_generic_channel_extraction_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.channel_extract";
  vx_enum k_id = VX_KERNEL_CHANNEL_EXTRACT;
}

static void
init_generic_channel_combine_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.channel_combine";
  vx_enum k_id = VX_KERNEL_CHANNEL_COMBINE;
}

static void
init_3x3_sobel_filter_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.sobel3x3";
  vx_enum k_id = VX_KERNEL_SOBEL_3x3;
}

static void
init_magnitude_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.magnitude";
  vx_enum k_id = VX_KERNEL_MAGNITUDE;
}

static void
init_phase_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.phase";
  vx_enum k_id = VX_KERNEL_PHASE;
}

static void
init_scale_image_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.scale";
  vx_enum k_id = VX_KERNEL_SCALE_IMAGE;
}

static void
init_table_lookup_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.table_lookup";
  vx_enum k_id = VX_KERNEL_TABLE_LOOKUP;
}

static void
init_histogram_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.histogram";
  vx_enum k_id = VX_KERNEL_HISTOGRAM;
}

static void
init_histogram_equalization_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.equalization";
  vx_enum k_id = VX_KERNEL_EQUALIZE_HISTOGRAM;
}

static void
init_absolute_difference_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.absdiff";
  vx_enum k_id = VX_KERNEL_ABSDIFF;
}

static void
init_mean_stddev_kernel (void) {

  vx_char name[] =  "org.khronos.openvx.mean_stddev";
  vx_enum k_id = VX_KERNEL_MEAN_STDDEV;
}
#endif
/* TODO: and lots of others ...
 * https://www.khronos.org/registry/vx/specs/1.0/html/d7/dcd/group__group__kernel.html#ga2814901a6714649927c52179a5bd422a
 */
