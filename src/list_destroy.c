#include "../lem_in.h"

void    list_destroy(List *list)
{
    void        *data;

    while (list_size(list) > 0)
    {
        if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
            list->destroy(data);
    }
    ft_memset(list, 0, sizeof(List));
    return;
}