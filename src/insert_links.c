#include "../lem_in.h"

void    insert_edges(Graph *graph, List *rooms, List *links, List *hold_malloc)
{
    list_elmt   *vertices;
    list_elmt   *holder;
    char        *link1;
    char        *link2;

    vertices = list_head(rooms);
    while (vertices != NULL)
    {
        holder = list_head(links);
        while (holder != NULL)
        {
            link1 = ft_strsub(holder->data, 0, ft_strchr((char*)holder->data, '-') - (char*)holder->data);
            link2 = ft_strsub(holder->data, (ft_strchr((char*)holder->data, '-') - (char*)holder->data) + 1, ft_strlen(holder->data));
            if (match((void*)link1, (void*)vertices->data))
                graph_ins_edge(graph, (void*)vertices->data, (void*)link2);
            if (match((void*)link2, (void*)vertices->data))
                graph_ins_edge(graph, (void*)vertices->data, (void*)link1);
            list_ins_next(hold_malloc, NULL, (void*)link1);
            list_ins_next(hold_malloc, NULL, (void*)link2);
            holder = list_next(holder);
        }
        vertices = list_next(vertices);
    }
}
