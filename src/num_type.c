#include "num_type.h"

Numeric* Numeric_New()
{
    Numeric* retVal = (Numeric*)calloc(1, sizeof(Numeric));

    return retVal;
}
