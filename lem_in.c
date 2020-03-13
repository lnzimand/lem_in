#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>

#define START "##start"
#define END "##end"

typedef struct      _links {
    char            *data;
    struct _links   *next;
}                   links;

typedef struct      _routes {
    char            *names;
    struct _routes  *paths[10];
}                   routes;

typedef struct      _head {
    char            *startName;
    char            *endName;
    struct links    *next;
}                   head;

char    *getPosition(char **arr, char *position)
{
    char     *pos_found;

    while (*arr)
    {
        if (!ft_strcmp(*arr, position))
            pos_found = ft_strdup(*(++arr));
        arr++;
    }
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
        ft_putendl(*arr);
        if (ft_strchr(*arr, '-'))
            storeLink(*arr, head);
        arr++;
    }
}

int     main(int argc, char **argv)
{
    links   *head;
    int     antsNumber;
    char    *start;
    char    *startName;
    char    *end;
    char    *endName;

    head = NULL;
    char **name;
    char *str = "3'##start'0 1 0'##end'1 5 0'2 9 0'3 13 0'0-2'2-3'3-1";
    char *str2 = "3'2 5 0'##start'0 1 2'##end'1 9 2'3 5 4'0-2'0-3'2-1'3-1'2-3";

    name = ft_strsplit(str2, '\'');
    antsNumber = getNumberOfAnts(*name);
    start = getPosition(name, START);
    startName = ft_strsub(start, 0, ft_strchr(start, ' ') - start);
    end = getPosition(name, END);
    endName = ft_strsub(end, 0, ft_strchr(end, ' ') - end);
    getLinks(name, &head);
    printf("Number of ants: %d\nStarting position: %s\nEnd position: %s\nStart pos name: %s\nEnd pos name: %s\n", antsNumber, start, end, startName, endName);
    ft_putendl("Links");
    while (head)
    {
        ft_putendl(head->data);
        head = head->next;
    }
    return (0);
}