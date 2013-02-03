#pragma once

#include <glib.h>

typedef struct
{
  char* node_type;
  char* node_value;
} ast_node;

GSList* GetASTList(GSList* tokenList);
