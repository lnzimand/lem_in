#include "../lem_in.h"

int     arr_length(char **arr)
{
    char    **temp;

    temp = arr;
    while(*temp)
        temp++;
    return (temp - arr);
}