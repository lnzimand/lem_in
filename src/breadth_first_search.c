/*****************************************************************************
*  ---------------------------- breadth first search ------------------------*
*****************************************************************************/
#include "../lem_in.h"
#include <stdio.h>

int bfs(Graph *graph, BfsVertex *start, List *hops, int ants, char *end_pos, \
char *start_pos, char **name)
{
    List        queue;
    adj_list    *adjlist;
    adj_list    *clr_adjlist;
    BfsVertex   *clr_vertex;
    BfsVertex   *adj_vertex;
    list_elmt   *element;
    list_elmt   *member;

    /* Initialize all of the vertices in the graph */
    element = list_head(&graph_adjlists(graph));
    while (element != NULL)
    {
        clr_vertex = ((adj_list*)list_data(element))->vertex;
        if (graph->match(clr_vertex, start->data))
        {
            /* initialize the start vertex */
            clr_vertex->color = gray;
            clr_vertex->hops = 0;
        }
        else
        {
            /* intitialize vertices other than the start vertex */
            clr_vertex->color = white;
            clr_vertex->hops = -1;
        }
        element = list_next(element);
    }
    /*****************************************************************************
    *  Initialize the queue with the adjacency list of the start vertex.         *
    *****************************************************************************/
    queue_init(&queue, NULL);
    if (graph_adjlist(graph, start->data, &clr_adjlist) != 0)
    {
        queue_destroy(&queue);
        return (-1);
    }
    if (queue_enqueue(&queue, clr_adjlist) != 0)
    {
        queue_destroy(&queue);
        return (-1);
    }
    /*****************************************************************************
    *  Perform breadth-first search.                                             *
    *****************************************************************************/
    while (queue_size(&queue) > 0)
    {
        adjlist = queue_peek(&queue);
        /* Traverse each vertex in the current adjacency list */
        member = list_head(&adjlist->adjacent);
        while (member != NULL)
        {
            adj_vertex = list_data(member);
            /* Determine the color of the next adjacent vertex */
            if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0)
            {
                queue_destroy(&queue);
                return (-1);
            }
            clr_vertex = clr_adjlist->vertex;
            /* Color each white vertex gray and enqueue its adjacency list */
            if (clr_vertex->color == white)
            {
                clr_vertex->parent = adjlist->vertex;
                clr_vertex->color = gray;
                clr_vertex->hops = ((BfsVertex*)adjlist->vertex)->hops + 1;
                if (queue_enqueue(&queue, clr_adjlist) != 0)
                {
                    queue_destroy(&queue);
                    return -1;
                }
            }
            member = list_next(member);
        }
        /* Dequeue the current adjacency list and color its vertex black */
        if (queue_dequeue(&queue, (void **)&adjlist) == 0)
            ((BfsVertex *)adjlist->vertex)->color = black;
        else
        {
            queue_destroy(&queue);
            return (-1);
        }
    }
    queue_destroy(&queue);
    /* Pass back the hop count for each vertex in a list */
    list_init(hops, NULL);
    element = list_head(&graph_adjlists(graph));
    while (element != NULL)
    {
        /* Skip vertices that were not visited (those with hop counts of -1) */
        clr_vertex = ((adj_list*)list_data(element))->vertex;
        if (clr_vertex->hops == -1)
        {
            if (list_ins_next(hops, list_tail(hops), clr_vertex) != 0)
            {
                list_destroy(hops);
                return (-1);
            }
        }
        element = list_next(element);
    }
    verify_connections(hops, end_pos, start_pos);
    print_map(name);
    create_path(graph, ants, end_pos, start_pos);
    return (0);
}