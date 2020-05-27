#include "../lem_in.h"

void    get_rooms(char **arr, list_elmt **rooms)
{
    char    *temp;
    // char    **holder;

    while (*arr)
    {
        if (!ft_strchr(*arr, '#') && !ft_strchr(*arr, '-'))
        {
            if (errors(*arr))
            {
                free_list_elmt(*rooms);
                error_handler("room coordinates ", "INCORRECT INPUT!");
            }
            // check_coordinates("room", *arr);
            temp = ft_strsub(*arr, 0, ft_strchr(*arr, ' ') - *arr);
            store_link(temp, rooms);
            ft_strdel(&temp);
        }
        arr++;
    }
    if (!rooms)
        error_handler("rooms", " NOT FOUND");
}
