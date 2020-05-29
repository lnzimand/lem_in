#include "../lem_in.h"

void    get_rooms(char **arr, List *rooms)
{
    char    *temp;
    char    **holder;

    holder = arr;
    ++arr;
    while (*arr)
    {
        if (!ft_strchr(*arr, '#') && !ft_strchr(*arr, '-'))
        {
            if (errors(*arr))
            {
                free_array(holder);
                list_destroy(rooms);
                free(rooms);
                error_handler("room coordinates ", "INCORRECT INPUT!");
            }
            // check_coordinates("room", *arr);
            temp = ft_strsub(*arr, 0, ft_strchr(*arr, ' ') - *arr);
            list_ins_next(rooms, NULL, temp);
        }
        arr++;
    }
    if (!rooms)
    {
        free_array(holder);
        list_destroy(rooms);
        free(rooms);
        error_handler("rooms", " NOT FOUND");
    }
}
