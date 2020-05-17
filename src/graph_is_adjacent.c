#include "../lem_in.h"

/*****************************************************************************
*  --------------------------- graph_is_adjacent --------------------------  *
*****************************************************************************/
int graph_is_adjacent(const Graph *graph, const void *data1, const void *data2)
{
    list_elmt           *element;
    // list_elmt           *prev;
    /*****************************************************************************
    *  Locate the adjacency list of the first vertex.                            *
    *****************************************************************************/
    // prev = NULL;
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data1, ((adj_list*)list_data(element))->vertex))
            break;
        // prev = element;
        element = list_next(element);
    }
    /*****************************************************************************
    *  Return if the first vertex was not found.                                 *
    *****************************************************************************/
    if (element == NULL)
        return 0;
    /*****************************************************************************
    *  Return whether the second vertex is in the adjacency list of the first.   *
    *****************************************************************************/
    return set_is_member(&((adj_list*)list_data(element))->adjacent, data2);
}