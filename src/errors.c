#include "../lem_in.h"

int     errors(char *room)
{
    char    *temp;
    char    **temp2;

    temp = ft_strchr((const char*)room, ' ');
    if (temp == NULL)
        return 1;
    temp2 = ft_strsplit((const char*)temp, ' ');
    if (!all_digits(temp2))
    {
        free_array(temp2);
        return 1;
    }
    free_array(temp2);
    return 0;
}
