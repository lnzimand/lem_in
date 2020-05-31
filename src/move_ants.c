#include "../lem_in.h"

void    move_ants(Path *path, int ants)
{
    path_elmt   *element;
    path_elmt   *from_start;
    int         new_line;
    char        *temp;

    new_line = 0;
    element = path_head(path);
    element->occupied = ants;
    element = path_tail(path);
    while (element->occupied != ants)
    {
        from_start = path_head(path);
        if ((!from_start->next->occupied && from_start->occupied != 0) \
        || from_start->next == path_tail(path))
        {
            temp = ft_itoa(from_start->occupied);
            from_start->next->ant_name = ft_strdup(temp);
            // printf("address ft_strdup: %p\n", from_start->next->ant_name);
            print_out(temp, from_start->next->room_name);
            ft_strdel(&temp);
            from_start->occupied--;
            from_start->next->occupied++;
            if (element->occupied != ants)
                ft_putchar('\n');
            new_line = 1;
        }
        if (!new_line)
            ft_putchar('\n');
        while (element->prev != from_start)
        {
            if (element->prev->occupied)
            {
                element->ant_name = element->prev->ant_name;
                element->occupied++;
                element->prev->occupied--;
                print_out(element->prev->ant_name, element->room_name);
                if (element->next == NULL)
                    free(element->ant_name);
            }
            element = path_prev(element);
        }
        if (element == path_tail(path))
            free(element->ant_name);
        new_line = 0;
        element = path_tail(path);
    }
    ft_putchar('\n');
}
