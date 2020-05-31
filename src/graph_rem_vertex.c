#include "../lem_in.h"

int     graph_rem_vertex(Graph *graph, void **data)
{
    list_elmt       *element;
    list_elmt       *temp;
    list_elmt       *prev;
    adj_list        *adjlist;
    int             found;

    prev = NULL;
    found = 0;
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (set_is_member(&((adj_list*)list_data(element))->adjacent, *data))
            return -1;
        if (graph->match(*data, ((adj_list*)list_data(element))->vertex))
        {
            temp = element;
            found = 1;
        }
        if (!found)
            prev = element;
        element = list_next(element);
    }
    if (!found)
        return -1;
    if (set_size(&((adj_list*)list_data(temp))->adjacent) > 0)
        return -1;
    if (list_rem_next(&graph->adjlists, prev, (void **)&adjlist) != 0)
        return -1;
    *data = adjlist->vertex;
    free(adjlist);
    graph->vcount--;
    return 0;
}