#include "../lem_in.h"

int graph_adjlist(const Graph *graph, const void *data, adj_list **adjlist)
{
    list_elmt       *element;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data, ((adj_list*)list_data(element))->vertex))
            break;
        element = list_next(element);
    }
    if (element == NULL)
        return -1;
    *adjlist = list_data(element);
    return 0;
}