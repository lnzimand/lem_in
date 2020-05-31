#include "../lem_in.h"

void    path_destroy(Path *path)
{
    void        *data;

    while (path_size(path) > 0)
    {
        if (path_rem_next(path, NULL, (void **)&data) == 0 && path->destroy != NULL)
            path->destroy(data);
    }
    ft_memset(path, 0, sizeof(Path));
    return;
}