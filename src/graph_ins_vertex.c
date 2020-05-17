#include "../lem_in.h"
/*****************************************************************************
*  --------------------------- graph_ins_vertex ---------------------------  *
******************************************************************************/

int graph_ins_vertex(Graph *graph, const void *data)
{
    list_elmt       *element;
    adj_list        *adjlist;
    int             retval;

    /*****************************************************************************
    *  Do not allow the insertion of duplicate vertices.                         *
    ******************************************************************************/
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        if (graph->match(data, ((adj_list *)list_data(element))->vertex))
            return 1;
        element = list_next(element);
    }
    /*****************************************************************************
    *  Insert the vertex.                                                        *
    *****************************************************************************/
    if ((adjlist = (adj_list *)malloc(sizeof(adj_list))) == NULL)
        return -1;
    adjlist->vertex = (void *)data;
    set_init(&adjlist->adjacent, graph->match, NULL);
    if ((retval = list_ins_next(&graph->adjlists, list_tail(&graph->adjlists), adjlist)) != 0)
        return retval;
    /*****************************************************************************
    *  Adjust the vertex count to account for the inserted vertex.               *
    *****************************************************************************/
    graph->vcount++;
    return 0;
}