#include "../lem_in.h"

void    get_rooms(char **arr, char *start, char *end, list_elmt **rooms)
{
    char    *temp;

    errors(start);
    errors(end);
    while (*arr)
    {
        if (ft_strcmp(*arr, start) && ft_strcmp(*arr, end) && \
        !ft_strchr(*arr, '#') && !ft_strchr(*arr, '-'))
        {
            errors(*arr);
            check_coordinates("room", *arr);
            temp = ft_strsub(*arr, 0, ft_strchr(*arr, ' ') - *arr);
            store_link(temp, rooms);
        }
        arr++;
    }
    if (!rooms)
        error_handler("rooms", " NOT FOUND");
}
