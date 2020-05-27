#include "../lem_in.h"

/* free dynamically allocated data */
void    path_destroy(Path *path)
{
    void        *data;

    while (path_size(path) > 0)
        path_rem_next(path, NULL, (void **)&data);
    ft_memset(path, 0, sizeof(Path));
    return;
}