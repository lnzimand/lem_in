#include "../lem_in.h"

int graph_rem_edge(Graph *graph, void *data1, void **data2)
{
    list_elmt       *element;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data1, ((adj_list*)list_data(element))->vertex))
            break;
        element = list_next(element);
    }
    if (element == NULL)
        return -1;
    if (set_remove(&((adj_list*)list_data(element))->adjacent, data2) != 0)
        return -1;
    graph->ecount--;
    return 0;
}