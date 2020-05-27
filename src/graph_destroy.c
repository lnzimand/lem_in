#include "../lem_in.h"
/*****************************************************************************
*  ----------------------------- graph_destroy ----------------------------  *
*****************************************************************************/

void graph_destroy(Graph *graph)
{
    adj_list        *adjlist;
    /*****************************************************************************
    *  Remove each adjacency-list structure and destroy its adjacency list.      *
    *****************************************************************************/
    while (list_size(&graph->adjlists) > 0) {
        if (list_rem_next(&graph->adjlists, NULL, (void **)&adjlist) == 0) {
            list_destroy(&adjlist->adjacent);
            free(adjlist);
        }
    }
    /*****************************************************************************
    *  Destroy the list of adjacency-list structures, which is now empty.        *
    *****************************************************************************/
    list_destroy(&graph->adjlists);
    /*****************************************************************************
    *  No operations are allowed now, but clear the structure as a precaution.   *
    *****************************************************************************/
    memset(graph, 0, sizeof(Graph));
    return;
}