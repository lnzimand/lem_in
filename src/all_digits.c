#include "../lem_in.h"

int    all_digits(char **arr)
{
    int     index;
    int     ins_index;

    index = 0;
    if (arr_length(arr) != 2)
        return 0;
    while (arr[index])
    {
        ins_index = 0;
        while (arr[index][ins_index])
        {
            if (!ft_isdigit(arr[index][ins_index]))
                return 0;
            ins_index++;
        }
        index++;
    }
    return 1;
}