#include "../lem_in.h"
/*****************************************************************************
*  ----------------------------- get_links --------------------------------  *
******************************************************************************/

void   get_links(char **arr, list_elmt **head)
{
    while (*arr)
    {
        /*****************************************************************************
        *  Store any string with '-'                                                 *
        ******************************************************************************/
        if (ft_strchr(*arr, '-'))
            store_link(*arr, head);
        arr++;
    }
}