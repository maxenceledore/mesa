#ifndef OVX_DEFINES_H
#define OVX_DEFINES_H

#include "VX/vx_vendors.h"

#define OVX_VENDOR_ID          VX_ID_MESA_GALLIUM
#define OVX_VENDOR_IMPL_NAME  "OpenVX over Mesa Gallium 0.4"

/* specs don't limit debug messages count,
 * as a KHR_debug_output with OpenGL for example.
 * but this implementation does it in its current
 * state.
 */
#define MAX_LOG_MESSAGE        1024

#endif
