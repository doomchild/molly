#pragma once

#include <glib.h>

enum NodeType { Open, Close, Whitespace, Symbol };

typedef struct
{
  enum NodeType node_type;
  char* node_value;
} ast_node;

GSList* GetASTList(GSList* tokenList);
