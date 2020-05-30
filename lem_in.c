#include "lem_in.h"

int     main(void)
{
    Graph       *graph;
    List        *links;
    List        *rooms;
    List        *holder;
    int         ants_number;
    char        *start;
    char        *end;
    char        **name;

    name = input_to_array();
    ants_number = get_number_of_ants(name);
    rooms = list_alloc();
    list_init(rooms, &free_alloc_mem);
    get_rooms(name, rooms);
    links = list_alloc();
    list_init(links, NULL);
    get_links(name, links);
    start = ft_strnew(1);
    end = ft_strnew(1);
    if (!get_start_end_pos(name, &start, &end))
    {
        free_array(name);
        list_destroy(rooms);
        list_destroy(links);
        free(rooms);
        free(links);
        error_handler("INCORRECT INPUT", " of start/end/coordinates");
    }
    graph = graph_alloc();
    graph_init(graph, &match, &free_alloc_mem);
    insert_vertices(graph, rooms);
    holder = list_alloc();
    list_init(holder, &free_alloc_mem);
    insert_edges(graph, rooms, links, holder);
    copy_graph(graph->adjlists, graph->ecount, graph->vcount, ants_number, end, \
    start, name);
    free_array(name);
    graph_destroy(graph);
    list_destroy(rooms);
    list_destroy(links);
    list_destroy(holder);
    free(holder);
    free(graph);
    free(links);
    free(rooms);
    free(start);
    free(end);
    return 0;
}
