#include "../lem_in.h"

int     get_start_end_pos(char **name, char **start, char **end)
{
    char    *start_name;
    char    *end_name;

    free(*start);
    free(*end);
    start_name = get_position(name, START);
    if (!start_name)
        return 0;
    end_name = get_position(name, END);
    if (!end_name)
    {
        ft_strdel(&start_name);
        return 0;
    }
    *start = ft_strsub(start_name, 0, ft_strchr(start_name, ' ') - start_name);
    *end = ft_strsub(end_name, 0, ft_strchr(end_name, ' ') - end_name);
    ft_strdel(&start_name);
    ft_strdel(&end_name);
    return 1;
}
