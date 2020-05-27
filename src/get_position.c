#include "../lem_in.h"
/*****************************************************************************
*  ----------------------------- get_position -----------------------------  *
******************************************************************************/

char    *get_position(char **arr, char *position)
{
    char    *pos_found;
    char    *str;

    pos_found = NULL;
    str = NULL;
    while (*arr)
    {
        /*********************************************************************
        *  If any of the array strings equals position, store position.       *
        ***********************************************************************/
        if (!ft_strcmp(*arr, position))
        {
            pos_found = ft_strdup(*(++arr));
            /******************************************************************
            *  Store string to check for validation of coordinations.         *
            *******************************************************************/
            str = ft_strchr(pos_found, ' ');
        }
        arr++;
    }
    /*************************************************************************
    *  Validation of a room.                                                 *
    **************************************************************************/
    if (!pos_found)
        error_handler(position, " NOT FOUND!");
    else if (!str)
        error_handler(position, " NOT FOUND!");
    else
        check_coordinates(position, str);
    return pos_found;
}
