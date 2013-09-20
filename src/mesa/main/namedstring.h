/*
 * Mesa 3-D graphics library
 *
 * Copyright (C) 2014-2015  Maxence Le Doré   All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */


#ifndef NAMEDSTRING_H
#define NAMEDSTRING_H

#include <stdbool.h>
#include "main/compiler.h"
#include "main/glheader.h"
#include "main/mtypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/**
 * Internal functions
 */
extern struct tree_node*
tree_loc_exists (struct gl_context *ctx, struct tree_node *from, GLint namelen,
                 const GLchar *name, const char* caller);

extern bool
named_string_path_valid(struct gl_context *ctx, GLint namelen,
                        const GLchar *name, const char* caller);

extern GLboolean
tree_loc_has_string_associated_with (struct tree_node* tn);

/**
 * API functions
 */

extern void GLAPIENTRY
_mesa_NamedStringARB(GLenum type, GLint namelen, const GLchar *name,
                     GLint stringlen, const GLchar *string);

extern void GLAPIENTRY
_mesa_DeleteNamedStringARB(GLint namelen, const GLchar *name);

extern GLboolean GLAPIENTRY
_mesa_IsNamedStringARB(GLint namelen, const GLchar *name);

extern void GLAPIENTRY
_mesa_GetNamedStringARB(GLint namelen, const GLchar *name,
                        GLsizei bufSize, GLint *stringlen, char *string);

extern void GLAPIENTRY
_mesa_GetNamedStringivARB(GLint namelen, const GLchar *name, GLenum pname,
                          GLint *params);

#ifdef __cplusplus
}
#endif

#endif /* NAMEDSTRING_H */