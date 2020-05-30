#include "../lem_in.h"

void    create_path(Graph *graph, int ants_number, char *end, char *start)
{
    Path        *path;
    BfsVertex   *clr_vertex;
    list_elmt   *element;
    char        *room_holder;

    path = (Path*)malloc(sizeof(Path));
    path_init(path, NULL);
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        room_holder = ((adj_list*)list_data(element))->vertex;
        if (match((void*)room_holder, (void*)end) && !match((void*)room_holder, (void*)start))
        {
            path_ins_next(path, NULL, (void*)end);
            clr_vertex = &((adj_list*)list_data(element))->bfs_vertex;
            end = clr_vertex->parent;
            element = list_head(&graph->adjlists);
            if (end != NULL)
                continue;
            else
                break;
        }
        element = list_next(element);
    }
    path_ins_next(path, NULL, (void*)end);
    move_ants(path, ants_number);
    path_destroy(path);
    free(path);
}
