#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "lem_in.h"

#define START "##start"
#define END "##end"

typedef struct      _links {
    char            *data;
    struct _links   *next;
}                   links;

// typedef struct      _trie_node {
//     struct _trie_node   *paths[10];
// }                   routes;

typedef struct      _root {
    char            *startName;
    struct routes   *next;
}                   root;

void    print_array(char **arr)
{
    while (*arr)
    {
        ft_putendl(*arr);
        arr++;
    }
}

void    error_handler(char *position, char  *error_msg)
{
    char    *str;

    str = ft_strjoin(ft_strdup("Error: "), position);
    str = ft_strjoin(str, error_msg);
    ft_putendl(str);
    exit(1);
}

void    check_coordinates(char *position, char *str)
{
    if (ft_strchr(++str, ' '))
    {
        str = ft_strchr(++str, ' ');
        if (!ft_isdigit(*++str))
            error_handler(position, " INCORRECT INPUT!");
    }
    else
        error_handler(position, " INCORRECT INPUT!");
    
}

int     arr_length(char **arr)
{
    char    **temp;

    temp = arr;
    while(*temp)
        temp++;
    return (temp - arr);
}

void    all_digits(char **arr)
{
    if (arr_length(arr) != 2)
        error_handler("room coordinate: ", "INCORRECT INPUT!");
    while (*arr)
    {
        while (**arr)
        {
            if (!ft_isdigit(**arr))
                error_handler("room coordinate: ", "INCORRECT INPUT!");
            (*arr)++;
        }
        arr++;
    }
    return ;
}

void    errors(char *room)
{
    char    *temp;
    char    **temp2;

    temp = ft_strchr((const char*)room, ' ');
    temp2 = ft_strsplit((const char*)temp, ' ');
    all_digits(temp2);
    return ;
}

char    *getPosition(char **arr, char *position)
{
    char    *pos_found;
    char    *str;

    pos_found = NULL;
    str = NULL;
    while (*arr)
    {
        if (!ft_strcmp(*arr, position))
        {
            pos_found = ft_strdup(*(++arr));
            str = ft_strchr(pos_found, ' ');
        }
        arr++;
    }
    if (!pos_found)
        error_handler(position, " NOT FOUND!");
    else if (!str)
        error_handler(position, " NOT FOUND!");
    else
        check_coordinates(position, str);
    return pos_found;
}

int     getNumberOfAnts(char *str)
{
    char    *temp;

    temp = ft_strtrim(str);
    if (!temp)
        error_handler("ants number ", "INCORRECT INPUT!");
    while (*temp)
    {
        if (!ft_isdigit(*temp))
            error_handler("ants number ", "INCORRECT INPUT!");
        temp++;
    }
    return ft_atoi(str);
}

links   *linkAlloc(void)
{
    links *temp;

    temp = malloc(sizeof(links));
    temp->next = NULL;
    return (temp);
}

void    storeLink(char *str, links **head)
{
    links   *temp;
    links   *store;

    if (!(*head))
    {
        *head = linkAlloc();
        (*head)->data = ft_strdup(str);
    }
    else
    {
        temp = *head;
        store = linkAlloc();
        while (temp->next)
            temp = temp->next;
        store->data = ft_strdup(str);
        temp->next = store;
    }
}

void   getLinks(char **arr, links **head)
{
    while (*arr)
    {
        if (ft_strchr(*arr, '-'))
            storeLink(*arr, head);
        arr++;
    }
}

void    getRooms(char **arr, char *start, char *end, links **rooms)
{
    char    *temp;

    errors(start);
    errors(end);
    while (*arr)
    {
        if (ft_strcmp(*arr, start) && ft_strcmp(*arr, end) && \
        !ft_strchr(*arr, '#') && !ft_strchr(*arr, '-'))
        {
            errors(*arr);
            check_coordinates("room", *arr);
            temp = ft_strsub(*arr, 0, ft_strchr(*arr, ' ') - *arr);
            storeLink(temp, rooms);
        }
        arr++;
    }
    if (!(*rooms))
        error_handler("rooms", " NOT FOUND");
}

char    *read_input(void)
{
    char    *str;
    char    *line;

    str = "";
    while (get_next_line(0, &line) > 0)
    {
        str = ft_strjoin(str, line);
        str = ft_strjoin(str, "'");
    }
    return (str);
}

int     match(const void *data1, const void *data2)
{
    if (!ft_strcmp((char*)data1, (char*)data2))
        return 1;
    return 0;
}

Graph   *graph_alloc(void)
{
    Graph   *new_graph;

    if (!(new_graph = (Graph*)malloc(sizeof(Graph))))
        error_handler("Allocating memory for graph:", "Insufficient memory");
    return new_graph;
}

void    print_graph(Graph *graph)
{
    list_elmt   *element;
    list_elmt   *adj_element;
    char        *holder;

    element = list_head(&graph->adjlists);
    while (element != NULL)
    {
        holder = ((adj_list*)list_data(element))->vertex;
        ft_putendl("Room");
        ft_putendl(holder);
        adj_element = (((adj_list*)list_data(element))->adjacent).head;
        ft_putendl("Connected to");
        while (adj_element != NULL)
        {
            holder = adj_element->data;
            ft_putendl(holder);
            adj_element = list_next(adj_element);
        }
        
        // adj_element = ((adj_list*)list_data(adj_element)->adjacent)
        element = list_next(element);
    }
}

int     main(void)
{
    links   *head;
    links   *holder;
    links   *vertices;
    links   *v_holder;
    int     antsNumber;
    char    *start;
    char    *end;
    char    *startName;
    char    *endName;
    char    **name;
    char    *str;
    char    *link1;
    char    *link2;
    Graph   *graph;

    graph = graph_alloc();
    graph_init(graph, &match, &graph_destroy);
    head = NULL;
    vertices = NULL;
    str = read_input();
    name = ft_strsplit(str, '\'');
    antsNumber = getNumberOfAnts((*name));
    startName = getPosition(name, START);
    start = ft_strsub(startName, 0, ft_strchr(startName, ' ') - startName);
    storeLink(start, &vertices);
    endName = getPosition(name, END);
    end = ft_strsub(endName, 0, ft_strchr(endName, ' ') - endName);
    storeLink(end, &vertices);
    getLinks(name, &head);
    getRooms(++name, startName, endName, &vertices);
    ft_putendl("links");
    holder = head;
    while (holder) {
        link1 = ft_strsub(holder->data, 0, ft_strchr(holder->data, '-') - holder->data);
        link2 = ft_strsub(holder->data, (ft_strchr(holder->data, '-') - holder->data) + 1, ft_strlen(holder->data));
        ft_putendl(holder->data);
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
            link1 = ft_strsub(holder->data, 0, ft_strchr(holder->data, '-') - holder->data);
            link2 = ft_strsub(holder->data, (ft_strchr(holder->data, '-') - holder->data) + 1, ft_strlen(holder->data));
            if (match((void*)link1, (void*)v_holder->data))
                graph_ins_edge(graph, (void*)v_holder->data, (void*)link2);
            if (match((void*)link2, (void*)v_holder->data))
                graph_ins_edge(graph, (void*)v_holder->data, (void*)link1);
            holder = list_next(holder);
        }
        v_holder = list_next(v_holder);
    }
    print_graph(graph);
    return 0;
}
