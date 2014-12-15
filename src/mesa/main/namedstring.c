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

/**
 * \file namedstring.c
 * \author Maxence Le Doré
 *
 */
#include "context.h"
#include "enums.h"
#include "imports.h"
#include "hash.h"
#include "macros.h"
#include "namedstring.h"
#include "util/ralloc.h"

bool
named_string_path_valid(struct gl_context *ctx, GLint namelen,
                        const GLchar *name, const char* caller) {
   if(namelen < 0 && name)
     namelen = strlen(name);

   if(!name)
     return false;

  if(strlen(name) == 0)
    return false;

  if(name[0] != '/')
    return false;

  if(strstr(name, "//") != NULL)
    return false;

  if(name[namelen-1] == '/')
    return false;

  (void*)(caller);
  return true;
}

struct tree_node*
tree_loc_exists (struct gl_context *ctx, struct tree_node *from, GLint namelen,
                 const GLchar *name, const char* caller) {

  char *name_dup = strdup(name);
  char *token_ptr;
  struct tree_node *tn = from;

  if(tn == NULL)
    return NULL;

  if(named_string_path_valid(ctx, namelen, name, caller) == false)
    return NULL;

  token_ptr = strtok(name_dup,"/");

  while (token_ptr != NULL)
  {
    do {
      if(strcmp(tn->node_name, token_ptr) == 0) {
        tn = tn->child;
        break;
      }

    } while(tn->next);

    token_ptr = strtok (NULL, "/");
    tn = tn->child;
  }
  return NULL;
}


GLboolean
tree_loc_has_string_associated_with (struct tree_node* tn) {

  if(!tn)
    return GL_FALSE;

  return (tn->ns.string != NULL ? GL_TRUE : GL_FALSE);
}


void GLAPIENTRY
_mesa_NamedStringARB(GLenum type, GLint namelen, const GLchar *name,
                     GLint stringlen, const GLchar *string)
{
   GET_CURRENT_CONTEXT(ctx);
   struct tree_node *tn = NULL;
   struct gl_named_string *ns = NULL;
   bool valid;

   if(type != GL_SHADER_INCLUDE_ARB) {
     _mesa_error(ctx, GL_INVALID_ENUM,
                 "glNamedStringARB(type != GL_SHADER_INCLUDE_ARB)");
      return;
   }

   valid = named_string_path_valid (ctx, namelen, name, NULL);

   ns = &tn->ns;

   if(valid == true) {
     ns->Type = type;

     if(ns->string != NULL)
       free(ns->string);

     ns->string = _mesa_strdup(string);
     tn->DeletePending = GL_FALSE;
     /* tn->hash_id = _mesa_str_checksum(name); */
   }
   else
     _mesa_error(ctx, GL_INVALID_VALUE, "glNamedStringARB");
}


void GLAPIENTRY
_mesa_DeleteNamedStringARB(GLint namelen, const GLchar *name)
{
   GET_CURRENT_CONTEXT(ctx);
   struct tree_node *tn = NULL;
   struct gl_named_string *ns = NULL;
   GLboolean string_associated = GL_FALSE;

   tn = tree_loc_exists(ctx, &ctx->tree_loc_root, namelen, name,
                        "glDeleteNamedStringARB");

   string_associated = tree_loc_has_string_associated_with (tn);

   if(string_associated == GL_FALSE) {
     _mesa_error(ctx, GL_INVALID_OPERATION,
                 "glGetNamedStringivARB(invalid name)");
     return;
   }

   ns = &tn->ns;
   free(ns->string);
   ns->lenght = 0;
/* ns->Type = 0x0000; */
   return;
}


GLboolean GLAPIENTRY
_mesa_IsNamedStringARB(GLint namelen, const GLchar *name)
{
   GET_CURRENT_CONTEXT(ctx);
   struct tree_node *tn = NULL;
   GLboolean string_associated = GL_FALSE;

   tn = tree_loc_exists(ctx, &ctx->tree_loc_root, namelen, name,
                        "glIsNamedStringARB");

   string_associated = tree_loc_has_string_associated_with (tn);

   return string_associated;  
}


void GLAPIENTRY
_mesa_GetNamedStringARB(GLint namelen, const GLchar *name,
                        GLsizei bufSize, GLint *stringlen, char *string)
{
   GET_CURRENT_CONTEXT(ctx);
   struct tree_node *tn = NULL;
   struct gl_named_string *ns = NULL;
   GLsizei write_size = 0;

   tn = tree_loc_exists(ctx, &ctx->tree_loc_root, namelen, name,
                        "glGetNamedStringARB");

   if(tree_loc_has_string_associated_with (tn) == GL_FALSE) {
     _mesa_error(ctx, GL_INVALID_OPERATION,
                 "glGetNamedStringivARB(invalid name)");
     return;
   }

   ns = &tn->ns;

   write_size = MIN2(bufSize,ns->lenght);
   if(stringlen)
     *stringlen = write_size;

   memcpy(string, ns->string, write_size);

   if(bufSize <= ns->lenght)
     string[bufSize-1] = '\0';
}


void GLAPIENTRY
_mesa_GetNamedStringivARB(GLint namelen, const GLchar *name, GLenum pname,
                          GLint *params)
{
   GET_CURRENT_CONTEXT(ctx);
   struct tree_node *tn = NULL;
   struct gl_named_string *ns = NULL;

   tn = tree_loc_exists(ctx, &ctx->tree_loc_root, namelen, name,
                        "glGetNamedStringivARB");

   if(tree_loc_has_string_associated_with (tn) == GL_FALSE) {
     _mesa_error(ctx, GL_INVALID_OPERATION,
                 "glGetNamedStringivARB(invalid name)");
     return;
   }

   ns = &tn->ns;

   switch(pname) {
     case GL_NAMED_STRING_LENGTH_ARB:
       *params = ns->lenght;
       break;
     case GL_NAMED_STRING_TYPE_ARB:
       *params = ns->Type;
       break;
     default:
       _mesa_error(ctx, GL_INVALID_ENUM,
                 "glGetNamedStringivARB(invalid pname)");
   }
}
