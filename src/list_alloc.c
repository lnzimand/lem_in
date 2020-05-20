#include "../lem_in.h"

List    *list_alloc(void)
{
    List    *new_list;

    if (!(new_list = (List*)malloc(sizeof(List))))
        error_handler("Allocating memory for graph:", "Insufficient memory");
    return new_list;
}