#include "../lem_in.h"

list_elmt   *link_alloc(void)
{
    list_elmt   *temp;

    temp = malloc(sizeof(list_elmt));
    temp->next = NULL;
    return (temp);
}