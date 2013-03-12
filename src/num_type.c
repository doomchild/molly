#include "num_type.h"

MNumeric* MNumeric_New()
{
    MNumeric* retVal = (MNumeric*)calloc(1, sizeof(MNumeric));

    return retVal;
}
