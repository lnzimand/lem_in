#include "../lem_in.h"

Graph   *graph_alloc(void)
{
    Graph   *new_graph;

    if (!(new_graph = (Graph*)malloc(sizeof(Graph))))
        error_handler("Allocating memory for graph:", "Insufficient memory");
    return new_graph;
}
