#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>

#define START "##start"
#define END "##end"

typedef struct      _links {
    char            *data;
    struct _links   *next;
}                   links;

typedef struct      _trie_node {
    char                *names;
    struct _trie_node   *paths[10];
}                   routes;

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
    else if (!ft_strchr(++str, ' '))
        error_handler(position, " NOT FOUND!");
    return pos_found;
}

int     getNumberOfAnts(char *str)
{
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
    while (*arr)
    {
        if (ft_strcmp(*arr, start) && ft_strcmp(*arr, end) && \
        !ft_strchr(*arr, '#') && !ft_strchr(*arr, '-'))
            storeLink(*arr, rooms);
        arr++;
    }
    if (!(*rooms) && (!start || !end))
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

int     main(void)
{
    links   *head;
    links   *room;
    int     antsNumber;
    char    *start;
    char    *startName;
    char    *end;
    char    *endName;
    char    **name;
    char    *str;

    head = NULL;
    room = NULL;
    str = read_input();
    name = ft_strsplit(str, '\'');
    antsNumber = getNumberOfAnts((*name));
    start = getPosition(name, START);
    startName = ft_strsub(start, 0, ft_strchr(start, ' ') - start);
    end = getPosition(name, END);
    endName = ft_strsub(end, 0, ft_strchr(end, ' ') - end);
    getLinks(name, &head);
    getRooms(++name, start, end, &room);
    // getRoutes(start, antsNumber);
    ft_putendl("Ants Number");
    ft_putnbr(antsNumber);
    ft_putchar('\n');
    ft_putendl("Start postion");
    ft_putendl(start);
    ft_putendl("End postion");
    ft_putendl(end);
    ft_putendl("links");
    ft_putendl("Start name");
    ft_putendl(startName);
    ft_putendl("End name");
    ft_putendl(endName);
    ft_putendl("links");
    while (head) {
        ft_putendl(head->data);
        head = head->next;
    }
    ft_putendl("rooms");
    while (room)
    {
        ft_putendl(room->data);
        room = room->next;
    }
    return (0);
}
