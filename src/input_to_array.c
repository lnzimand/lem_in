#include "../lem_in.h"

char    **input_to_array(void)
{
    char    *str;
    char    **arr;

    str = read_input();
    arr = ft_strsplit(str, '\'');
    ft_strdel(&str);
    return arr;
}