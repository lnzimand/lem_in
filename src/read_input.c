#include "../lem_in.h"
/*****************************************************************************
*  ----------------------------- read_input--------------------------------  *
******************************************************************************/

char    *read_input(void)
{
    char    *str;
    char    *line;
    char    *holder;

    str = "";
    holder = ft_strnew(1);
    while (get_next_line(0, &line) > 0)
    {
        /*****************************************************************************
        *  Store lines from stdin with "'" as delimeter.                             *
        ******************************************************************************/
        str = ft_strjoin(str, line);
        ft_strdel(&line);
        ft_strdel(&holder);
        holder = str;
        str = ft_strjoin(str, "'");
        ft_strdel(&holder);
        holder = str;
    }
    if (ft_strlen(str) == 0)
    {
        free(holder);
        error_handler("INCORRECT ", "INPUT");
    }
    return (str);
}
