#include "../lem_in.h"

void    insert_vertices(Graph *graph, List *rooms)
{
    list_elmt   *element;

    element = list_head(rooms);
    while (element != NULL)
    {
        graph_ins_vertex(graph, element->data);
        element = list_next(element);
    }
}