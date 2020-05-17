#include "libft.h"

int     ft_strpos(char *str, char c)
{
    char    *temp;

    temp = str;
    while (*temp)
    {
        if (*temp == c)
            return(temp - str);
        temp++;
    }
    return (0);
}