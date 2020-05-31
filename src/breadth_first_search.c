#include "../lem_in.h"

int bfs(Graph *graph, BfsVertex *start, List *hops, int ants, char *end_pos, \
char *start_pos, char **name)
{
    List        queue;
    adj_list    *adjlist;
    adj_list    *clr_adjlist;
    BfsVertex   *vertex;
    BfsVertex   *clr_vertex;
    BfsVertex   *adj_vertex;
    list_elmt   *element;
    list_elmt   *member;

    element = list_head(&graph_adjlists(graph));
    while (element != NULL)
    {
        vertex = ((adj_list*)list_data(element))->vertex;
        clr_vertex = &((adj_list*)list_data(element))->bfs_vertex;
        if (graph->match(vertex, start->data))
        {
            clr_vertex->color = gray;
            clr_vertex->hops = 0;
        }
        else
        {
            clr_vertex->color = white;
            clr_vertex->hops = -1;
        }
        element = list_next(element);
    }
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
    while (queue_size(&queue) > 0)
    {
        adjlist = queue_peek(&queue);
        member = list_head(&adjlist->adjacent);
        while (member != NULL)
        {
            adj_vertex = list_data(member);
            if (graph_adjlist(graph, adj_vertex, &clr_adjlist) != 0)
            {
                queue_destroy(&queue);
                return (-1);
            }
            clr_vertex = &clr_adjlist->bfs_vertex;
            if (clr_vertex->color == white)
            {
                clr_vertex->parent = adjlist->vertex;
                clr_vertex->color = gray;
                clr_vertex->hops = adjlist->bfs_vertex.hops + 1;;
                if (queue_enqueue(&queue, clr_adjlist) != 0)
                {
                    queue_destroy(&queue);
                    return -1;
                }
            }
            member = list_next(member);
        }
        if (queue_dequeue(&queue, (void **)&adjlist) == 0)
            adjlist->bfs_vertex.color = black;
        else
        {
            queue_destroy(&queue);
            return (-1);
        }
    }
    queue_destroy(&queue);
    list_init(hops, NULL);
    element = list_head(&graph_adjlists(graph));
    while (element != NULL)
    {
        clr_vertex = &((adj_list*)list_data(element))->bfs_vertex;
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