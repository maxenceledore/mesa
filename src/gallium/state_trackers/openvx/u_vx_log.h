#ifndef _U_VX_LOG_H
#define _U_VX_LOG_H

#include <stdio.h>
#include <string.h>

#include "ovx_types.h"

extern void
u_log_message(vx_context context, vx_enum type, const vx_char *message);

#endif /* _U_VX_LOG_H */