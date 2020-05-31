#include "../lem_in.h"

void graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
    graph->vcount = 0;
    graph->ecount = 0;
    graph->match = match;
    graph->destroy = destroy;
    
    list_init(&graph->adjlists, NULL);
    return;
}