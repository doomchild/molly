#pragma once

#include <glib.h>
#include <stdlib.h>
#include <stdint.h>
#include "type.h"

typedef struct
{
    Type type;
    uint16_t flags;
    void *value;
} MNumeric;

MNumeric* MNumeric_New();
