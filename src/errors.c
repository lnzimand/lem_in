#include "../lem_in.h"

void    errors(char *room)
{
    char    *temp;
    char    **temp2;

    temp = ft_strchr((const char*)room, ' ');
    if (temp == NULL)
        error_handler("rooms ", "INCORRECT INPUT");
    temp2 = ft_strsplit((const char*)temp, ' ');
    all_digits(temp2);
    return ;
}
