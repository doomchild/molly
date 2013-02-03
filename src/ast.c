#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

ast_node* ast_node_alloc()
{
  return (ast_node*)calloc(sizeof(ast_node), 1);
}

void free_ast_node(ast_node* node)
{
  free(node->node_type);
  free(node->node_value);
  free(node);
}

GSList* GetASTList(GSList* tokenList)
{
    GSList* astList = NULL;
    GSList* iterator = NULL;

    for(iterator = tokenList; iterator; iterator = iterator->next)
    {
	ast_node* node = ast_node_alloc();
	char* value = (char*)iterator->data;

	if(value[0] == '(')
	{
	    node->node_type = "Open\0";
	    node->node_value = "(\0";
	}
	else if(value[0] == ')')
	{
	    node->node_type = "Close\0";
	    node->node_value = ")\0";
	}
	else if(isspace(value[0]))
	{
	    node->node_type = "Whitespace\0";
	    node->node_value = (char*)calloc(sizeof(char), 2);
	    node->node_value[0] = value[0];
	    node->node_value[1] = '\0';
	}
	else
	{
	    size_t len = strlen(value);

	    node->node_type = "Symbol\0";
	    node->node_value = (char*)calloc(sizeof(char), len + 1);

	    strncpy(node->node_value, value, len);
	    node->node_value[len] = '\0';
	}
      
	astList = g_slist_append(astList, node);
    }
  
    return astList;
}
