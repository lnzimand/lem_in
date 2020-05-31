#include "../lem_in.h"

void    error_handler(char *position, char  *error_msg)
{
    char    *str;
    char    *temp;

    temp = ft_strdup("Error: ");
    str = ft_strjoin(temp, position);
    ft_strdel(&temp);
    temp = str;
    str = ft_strjoin(str, error_msg);
    ft_strdel(&temp);
    ft_putendl(str);
    ft_strdel(&str);
    exit(1);
}