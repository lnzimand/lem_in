#include "../lem_in.h"

int graph_ins_edge(Graph *graph, const void *data1, const void *data2)
{
    list_elmt       *element;
    int             retval;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data2, ((adj_list*)list_data(element))->vertex))
            break;
        element = list_next(element);
    }
    if (element == NULL)
        return -1;
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data1, ((adj_list*)list_data(element))->vertex))
            break;
        element = list_next(element);
    }
    if (element == NULL)
        return -1;
    if ((retval = set_insert(&((adj_list*)list_data(element))->adjacent, data2)) != 0)
        return retval;
    graph->ecount++;
    return 0;
}