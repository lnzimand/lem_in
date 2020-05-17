#include "../lem_in.h"

/*****************************************************************************
*  ---------------------------- graph_rem_edge ----------------------------  *
*****************************************************************************/
int graph_rem_edge(Graph *graph, void *data1, void **data2)
{
    list_elmt       *element;

    /*****************************************************************************
    *  Locate the adjacency list for the first vertex.                           *
    ******************************************************************************/
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data1, ((adj_list*)list_data(element))->vertex))
            break;
        element = list_next(element);
    }
    if (element == NULL)
        return -1;
    /*****************************************************************************
    *  Remove the second vertex from the adjacency list of the first vertex.     *
    *****************************************************************************/
    if (set_remove(&((adj_list*)list_data(element))->adjacent, data2) != 0)
        return -1;
    /*****************************************************************************
    *  Adjust the edge count to account for the removed edge.                    *
    *****************************************************************************/
    graph->ecount--;
    return 0;
}