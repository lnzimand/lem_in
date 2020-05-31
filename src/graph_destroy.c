#include "../lem_in.h"

void graph_destroy(Graph *graph)
{
    adj_list        *adjlist;
    while (list_size(&graph->adjlists) > 0)
    {
        if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0)
        {
            list_destroy(&adjlist->adjacent);
            free(adjlist);
        }
    }
    list_destroy(&graph->adjlists);
    memset(graph, 0, sizeof(Graph));
    return;
}