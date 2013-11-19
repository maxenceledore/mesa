
#ifndef U_VX_CONTEXT_H
#define U_VX_CONTEXT_H

#include "VX/vx.h"


#include "pipe/p_format.h"
#include "pipe/p_state.h"
#include "state_tracker/st_api.h"

#include "cso_cache/cso_hash.h"
#include "cso_cache/cso_context.h"

struct st_renderbuffer {
   enum pipe_format   format;
   struct pipe_surface *surface;
   struct pipe_resource *texture;
   vx_int32 width, height;
};

#endif
