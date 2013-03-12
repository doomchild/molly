#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"

#define molly_VERSION_MAJOR 0
#define molly_VERSION_MINOR 1

GSList* Tokenize(char* input, size_t len)
{
    GSList* elementList = NULL;
    int i;

    for(i = 0; i < len; i++)
    {
	char* token;

	if(input[i] == '(' || input [i] == ')')
	{
	    token = (char*)calloc(sizeof(char), 2);
	    token[0] = input[i];
	    token[1] = '\0';

	    elementList = g_slist_append(elementList, token);
	}
	else if(isspace(input[i]))
	{
	    int len = 1;
	    char c = input[i + len];

	    while(isspace(c))
	    {
		len++;
		c = input[i + len];
	    }

	    token = (char*)calloc(sizeof(char), len + 1);
	    token[len] = '\0';
	    strncpy(token, input + i, len);

	    i += len - 1;

	    elementList = g_slist_append(elementList, token);
	}
	else
	{
	    int len = 1;
	    char c = input[i + len];

	    while(c != '(' && c != ')' && !isspace(c))
	    {
		len++;
		c = input[i + len];
	    }

	    token = (char*)calloc(sizeof(char), len + 1);
	    token[len] = '\0';
	    strncpy(token, input + i, len);

	    i += len - 1;

	    elementList = g_slist_append(elementList, token);
	}
    }

    return elementList;
}

int main(int argc, char** argv)
{
    if(argc > 1)
    {
	GSList* elementList = Tokenize(argv[1], strlen(argv[1]));
	GSList* astList = GetASTList(elementList);
	GSList* iterator = NULL;

	for(iterator = astList; iterator; iterator = iterator->next)
	{
	    printf("%s\n", ((ast_node*)iterator->data)->node_value);
	}
    }
    else
	printf("%s Version %d.%d\n", argv[0], molly_VERSION_MAJOR, molly_VERSION_MINOR);

    return 0;
}
