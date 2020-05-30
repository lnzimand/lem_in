#include "../lem_in.h"

void    copy_graph(List list, int ecount, int vcount, int ants_number, char *end, \
char *start, char **name)
{
    Graph   *graph;
    BfsVertex   bfs_start;
    List        *hops;

    graph = graph_alloc();
    graph->ecount = ecount;
    graph->vcount = vcount;
    graph->adjlists = list;
    graph->match = match;
    graph->destroy = NULL;

    
    bfs_start.data = ft_strdup(start);
    hops = list_alloc();
    list_init(hops, &free_alloc_mem);

    bfs(graph, &bfs_start, hops, ants_number, end, start, name);
    list_destroy(hops);
    free(hops);
    free(bfs_start.data);
    free(graph);
}