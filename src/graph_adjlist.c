#include "../lem_in.h"

/*****************************************************************************
*  ----------------------------- graph_adjlist ----------------------------  *
*****************************************************************************/
int graph_adjlist(const Graph *graph, const void *data, adj_list **adjlist)
{
    list_elmt       *element;
    // list_elmt       *prev;
    /*****************************************************************************
    *  Locate the adjacency list for the vertex.                                 *
    *****************************************************************************/
    // prev = NULL;
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data, ((adj_list*)list_data(element))->vertex))
            break;
        // prev = element;
        element = list_next(element);
    }
    /*****************************************************************************
    *  Return if the vertex was not found.                                       *
    *****************************************************************************/
    if (element == NULL)
        return -1;
    /*****************************************************************************
    *  Pass back the adjacency list for the vertex.                              *
    *****************************************************************************/
    *adjlist = list_data(element);
    return 0;
}