#include "../lem_in.h"

void    create_path(Graph *graph, int ants_number, char *end)
{
    Path        *path;
    BfsVertex   *clr_vertex;
    list_elmt   *element;
    char        *room_holder;

    path = (Path*)malloc(sizeof(Path));
    path_init(path);
    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        room_holder = ((adj_list*)list_data(element))->vertex;
        if (match((void*)room_holder, (void*)end))
        {
            path_ins_next(path, NULL, (void*)end);
            clr_vertex = ((adj_list*)list_data(element))->vertex;
            end = clr_vertex->parent;
            element = list_head(&graph->adjlists);
        }
        element = list_next(element);
    }
    path_ins_next(path, NULL, (void*)end);
    move_ants(path, ants_number);
}
