#include "lem_in.h"

/*****************************************************************************
*  ----------------------------- input_to_array ---------------------------  *
******************************************************************************/

char    **input_to_array(void)
{
    char    *str;
    char    **arr;

    /***********************************************************************
    *  Get string, delimetered by "'", from stdin.                         *
    ************************************************************************/
    str = read_input();
    /***********************************************************************
    *  Break up a string, delimetered by "'" into an array                 *
    ************************************************************************/
    arr = ft_strsplit(str, '\'');
    ft_strdel(&str);
    return arr;
}

int     get_start_end_pos(char **name, char **start, char **end)
{
    char    *start_name;
    char    *end_name;

    start_name = get_position(name, START);
    if (!start_name)
        return 0;
    end_name = get_position(name, END);
    if (!end_name)
    {
        ft_strdel(&start_name);
        return 0;
    }
    *start = ft_strsub(start_name, 0, ft_strchr(start_name, ' ') - start_name);
    *end = ft_strsub(end_name, 0, ft_strchr(end_name, ' ') - end_name);
    ft_strdel(&start_name);
    ft_strdel(&end_name);
    return 1;
}

void    insert_edges(Graph *graph, List *rooms, List *links)
{
    list_elmt   *vertices;
    list_elmt   *holder;
    char        *link1;
    char        *link2;

    vertices = list_head(rooms);
    while (vertices != NULL)
    {
        holder = list_head(links);
        while (holder != NULL)
        {
            link1 = ft_strsub(holder->data, 0, ft_strchr((char*)holder->data, '-') - (char*)holder->data);
            link2 = ft_strsub(holder->data, (ft_strchr((char*)holder->data, '-') - (char*)holder->data) + 1, ft_strlen(holder->data));
            if (match((void*)link1, (void*)vertices->data))
                graph_ins_edge(graph, (void*)vertices->data, (void*)ft_strdup(link2));
            if (match((void*)link2, (void*)vertices->data))
                graph_ins_edge(graph, (void*)vertices->data, (void*)ft_strdup(link1));
            ft_strdel(&link1);
            ft_strdel(&link2);
            holder = list_next(holder);
        }
        vertices = list_next(vertices);
    }
}

/*****************************************************************************
*  --------------------- insert rooms in a graph --------------------------  *
******************************************************************************/

void    insert_vertices(Graph *graph, List *rooms)
{
    list_elmt   *element;

    element = list_head(rooms);
    while (element != NULL)
    {
        graph_ins_vertex(graph, ft_strdup(element->data));
        element = list_next(element);
    }
}

void    remove_edges(Graph *graph, List *rooms, List *links)
{
    list_elmt   *vertices;
    list_elmt   *holder;
    char        *link1;
    char        *link2;

    vertices = list_head(rooms);
    while (vertices != NULL)
    {
        holder = list_head(links);
        while (holder != NULL)
        {
            link1 = ft_strsub(holder->data, 0, ft_strchr((char*)holder->data, '-') - (char*)holder->data);
            link2 = ft_strsub(holder->data, (ft_strchr((char*)holder->data, '-') - (char*)holder->data) + 1, ft_strlen(holder->data));
            if (match((void*)link1, (void*)vertices->data))
                graph_rem_edge(graph, (void*)vertices->data, (void**)&link2);
            if (match((void*)link2, (void*)vertices->data))
                graph_rem_edge(graph, (void*)vertices->data, (void**)&link1);
            ft_strdel(&link1);
            ft_strdel(&link2);
            holder = list_next(holder);
        }
        vertices = list_next(vertices);
    }
}

int     main(void)
{
    Graph       *graph;
    BfsVertex   bfs_start;
    List        *hops;
    List        *links;
    List        *rooms;
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
    list_init(links, &free_alloc_mem);
    get_links(name, links);
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
    insert_edges(graph, rooms, links);
    bfs_start.data = ft_strdup(start);
    hops = list_alloc();
    list_init(hops, &free_alloc_mem);
    bfs(*graph, &bfs_start, hops, ants_number, end, start, name);
    // remove_edges(graph, rooms, links);
    free_array(name);
    // graph_destroy(graph);
    list_destroy(rooms);
    list_destroy(links);
    list_destroy(hops);
    free(graph);
    free(hops);
    free(links);
    free(rooms);
    free(bfs_start.data);
    return 0;
}
