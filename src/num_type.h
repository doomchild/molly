#include <glib.h>
#include <stdlib.h>
#include <stdint.h>
#include "type.h"

typedef struct Numeric
{
    Type type;
    uint16_t flags;
    void *value;
};

Numeric* Numeric_New();
