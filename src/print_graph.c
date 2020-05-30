#include "../lem_in.h"

void    print_graph(Graph *graph)
{
    BfsVertex   *clr_vertex;
    list_elmt   *element;
    list_elmt   *adj_element;
    char        *holder;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        holder = ((adj_list*)list_data(element))->vertex;
        clr_vertex = &((adj_list*)list_data(element))->bfs_vertex;
        adj_element = (((adj_list*)list_data(element))->adjacent).head;
        ft_putstr("Room: ");
        ft_putendl(holder);
        ft_putendl("Parent name");
        ft_putendl((char*)clr_vertex->parent);
        ft_putendl("Number of hops from start");
        ft_putnbr(clr_vertex->hops);
        ft_putchar('\n');
        ft_putendl("Connected to");
        while (adj_element != NULL)
        {
            holder = adj_element->data;
            ft_putendl(holder);
            adj_element = list_next(adj_element);
        }
        element = list_next(element);
    }
}