#include "../lem_in.h"

/*****************************************************************************
*  --------------------------- graph_rem_vertex ---------------------------  *
*****************************************************************************/

int     graph_rem_vertex(Graph *graph, void **data)
{
    list_elmt       *element;
    list_elmt       *temp;
    list_elmt       *prev;
    adj_list        *adjlist;
    int             found;

    /*****************************************************************************
    *  Traverse each adjacency list and the vertices it contains.                **                                                                            *
    *****************************************************************************/
    prev = NULL;
    found = 0;
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        /**************************************************************************
         *  Do not allow removal of the vertex if it is in an adjacency list.      *
         **************************************************************************/
        if (set_is_member(&((adj_list*)list_data(element))->adjacent, *data))
            return -1;
        /**************************************************************************
         *  Keep a pointer to the vertex to be removed.                            *
         **************************************************************************/
        if (graph->match(*data, ((adj_list*)list_data(element))->vertex))
        {
            temp = element;
            found = 1;
        }
        /**************************************************************************
         *  Keep a pointer to the vertex before the vertex to be removed.          *
         **************************************************************************/
        if (!found)
            prev = element;
        element = list_next(element);
    }
    /*****************************************************************************
    *  Return if the vertex was not found.                                       *
    *****************************************************************************/
    if (!found)
        return -1;
    /*****************************************************************************
    *  Do not allow removal of the vertex if its adjacency list is not empty.    *
    *****************************************************************************/
    if (set_size(&((adj_list*)list_data(temp))->adjacent) > 0)
        return -1;
    /*****************************************************************************
    *  Remove the vertex.                                                        *
    *****************************************************************************/
    if (list_rem_next(&graph->adjlists, prev, (void **)&adjlist) != 0)
        return -1;
    /*****************************************************************************
    *  Free the storage allocated by the abstract datatype.                      *
    *****************************************************************************/
    *data = adjlist->vertex;
    free(adjlist);
    /*****************************************************************************
    *  Adjust the vertex count to account for the removed vertex.                *
    *****************************************************************************/
    graph->vcount--;
    return 0;
}