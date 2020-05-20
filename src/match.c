#include "../lem_in.h"

int     match(const void *data1, const void *data2)
{
    if (!ft_strcmp((char*)data1, (char*)data2))
        return 1;
    return 0;
}