#include "../lem_in.h"

char    *read_input(void)
{
    char    *str;
    char    *line;

    str = "";
    while (get_next_line(0, &line) > 0)
    {
        str = ft_strjoin(str, line);
        str = ft_strjoin(str, "'");
    }
    return (str);
}
