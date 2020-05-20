#include "../lem_in.h"

void    all_digits(char **arr)
{
    if (arr_length(arr) != 2)
        error_handler("room coordinates ", "INCORRECT INPUT!");
    while (*arr)
    {
        while (**arr)
        {
            if (!ft_isdigit(**arr))
                error_handler("room coordinates ", "INCORRECT INPUT!");
            (*arr)++;
        }
        arr++;
    }
    return ;
}