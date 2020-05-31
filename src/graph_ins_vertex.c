#include "../lem_in.h"

int graph_ins_vertex(Graph *graph, const void *data)
{
    list_elmt       *element;
    adj_list        *adjlist;
    int             retval;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data, ((adj_list *)list_data(element))->vertex))
            return 1;
        element = list_next(element);
    }
    if ((adjlist = (adj_list *)malloc(sizeof(adj_list))) == NULL)
        return -1;
    adjlist->vertex = (void *)data;
    set_init(&adjlist->adjacent, graph->match, NULL);
    if ((retval = list_ins_next(&graph->adjlists, list_tail(&graph->adjlists), adjlist)) != 0)
        return retval;
    graph->vcount++;
    return 0;
}