#include "../lem_in.h"

int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2)
{
    list_elmt           *element;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data1, ((adj_list*)list_data(element))->vertex))
        element = list_next(element);
    }
    if (element == NULL)
        return 0;
    return set_is_member(&((adj_list*)list_data(element))->adjacent, data2);
}