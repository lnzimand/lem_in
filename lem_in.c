#include "lem_in.h"

void    verify_connections(List *hops, void *end, void *start)
{
    list_elmt   *element;

    element = list_head(hops);
    while (element != NULL)
    {
        if (match(element->data, end) || match(element->data, start))
            error_handler("NO POSSIBLE SOLUTION ", "End/Start NOT CONNECTED!");
        element = list_next(element);
    }
    
}

void    print_map(char **arr, int ants_number)
{
    ft_putnbr(ants_number);
    ft_putchar('\n');
    print_array(arr);
    ft_putchar('\n');
}

int     main(void)
{
    BfsVertex   bfs_start;
    List        *hops;
    list_elmt   *head;
    list_elmt   *holder;
    list_elmt   *vertices;
    list_elmt   *v_holder;
    int         ants_number;
    char        *start;
    char        *end;
    char        *start_name;
    char        *end_name;
    char        **name;
    char        *str;
    char        *link1;
    char        *link2;
    Graph       *graph;

    hops = list_alloc();
    graph = graph_alloc();
    graph_init(graph, &match, &graph_destroy);
    head = NULL;
    vertices = NULL;
    str = read_input();
    name = ft_strsplit(str, '\'');
    ants_number = get_number_of_ants((*name));
    start_name = get_position(name, START);
    start = ft_strsub(start_name, 0, ft_strchr(start_name, ' ') - start_name);
    store_link(start, &vertices);
    end_name = get_position(name, END);
    end = ft_strsub(end_name, 0, ft_strchr(end_name, ' ') - end_name);
    store_link(end, &vertices);
    get_links(name, &head);
    get_rooms(++name, start_name, end_name, &vertices);
    holder = head;
    while (holder) {
        link1 = ft_strsub(holder->data, 0, ft_strchr((char*)holder->data, '-') - (char*)holder->data);
        link2 = ft_strsub(holder->data, (ft_strchr((char*)holder->data, '-') - (char*)holder->data) + 1, ft_strlen(holder->data));
        holder = list_next(holder);
    }
    v_holder = vertices;
    while (v_holder)
    {
        graph_ins_vertex(graph, v_holder->data);
        v_holder = list_next(v_holder);
    }
    v_holder = vertices;
    while (v_holder)
    {
        holder = head;
        while (holder)
        {
            link1 = ft_strsub(holder->data, 0, ft_strchr((char*)holder->data, '-') - (char*)holder->data);
            link2 = ft_strsub(holder->data, (ft_strchr((char*)holder->data, '-') - (char*)holder->data) + 1, ft_strlen(holder->data));
            if (match((void*)link1, (void*)v_holder->data))
                graph_ins_edge(graph, (void*)v_holder->data, (void*)link2);
            if (match((void*)link2, (void*)v_holder->data))
                graph_ins_edge(graph, (void*)v_holder->data, (void*)link1);
            holder = list_next(holder);
        }
        v_holder = list_next(v_holder);
    }
    bfs_start.data = ft_strdup(start);
    bfs(graph, &bfs_start, hops);
    verify_connections(hops, end, start);
    print_map(name, ants_number);
    create_path(graph, ants_number, end);
    // graph_destroy(graph);
    return 0;
}
