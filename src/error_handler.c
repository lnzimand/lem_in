#include "../lem_in.h"

void    error_handler(char *position, char  *error_msg)
{
    char    *str;

    str = ft_strjoin(ft_strdup("Error: "), position);
    str = ft_strjoin(str, error_msg);
    ft_putendl(str);
    exit(1);
}