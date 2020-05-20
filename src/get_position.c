#include "../lem_in.h"

char    *get_position(char **arr, char *position)
{
    char    *pos_found;
    char    *str;

    pos_found = NULL;
    str = NULL;
    while (*arr)
    {
        if (!ft_strcmp(*arr, position))
        {
            pos_found = ft_strdup(*(++arr));
            str = ft_strchr(pos_found, ' ');
        }
        arr++;
    }
    if (!pos_found)
        error_handler(position, " NOT FOUND!");
    else if (!str)
        error_handler(position, " NOT FOUND!");
    else
        check_coordinates(position, str);
    return pos_found;
}
