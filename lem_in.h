/****************************
---------- list.h -----------
*****************************/

#ifndef LIST_H
#define LIST_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"


#define START "##start"
#define END "##end"

/* a structure for linked list elements */
typedef struct          list_elmt_
{
    void                *data;
    struct list_elmt_   *next;

}                       list_elmt;

/* a structure for linked lists */
typedef struct          List_
{
    int                 size;
    int                 (*match)(const void *key, const void *key2);
    void                (*destroy)(void *data);
    list_elmt           *head;
    list_elmt           *tail;
}                       List;

/* structure for room */
typedef struct          path_elmt_
{
    void                *room_name;
    void                *ant_name;
    int                 occupied;
    struct path_elmt_    *prev;
    struct path_elmt_   *next;
}                       path_elmt;

/* structure for room */
typedef struct      Path_
{
    int             size;
    path_elmt       *head;
    path_elmt       *tail;
}                   Path;

/* structure for adjacency list*/
typedef struct  adj_list_
{
    void        *vertex;
    List        adjacent;
}               adj_list;

/* structure for graphs */
typedef struct  Graph_
{
    int         vcount;
    int         ecount;

    int         (*match)(const void *key1, const void *key2);
    void        (*destroy)(struct Graph_ *data);

    List        adjlists;
}               Graph;

/* colors for vertices */
typedef enum    vertex_color_ {
                white,
                gray,
                black
}               vertex_color;

/*****************************************************************************
*  Define a structure for vertices in a breadth-first search.                *
*****************************************************************************/
typedef struct      BfsVertex_
{
    void            *data;
    vertex_color    color;
    void            *parent;
    int             hops;
}                   BfsVertex;

/* Public interface */
void        graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(Graph *data));
void        graph_destroy(Graph *graph);
void        list_init(List *list, void (*destroy)(void *data));
void        list_destroy(List *list);
int         graph_ins_vertex(Graph *graph, const void *data);
int         graph_ins_edge(Graph *graph, const void *data1, const void *data2);
int         graph_rem_vertex(Graph *graph, void **data);
int         graph_rem_edge(Graph *graph, void *data1, void **data2);
int         graph_adjlist(const Graph *graph, const void *data, adj_list **adjlist);
int         graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);
int         list_ins_next(List *list, list_elmt *element, const void *data);
int         list_rem_next(List *list, list_elmt *element, void **data);
void        set_init(List *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int         set_insert(List *set, const void *data);
int         set_is_member(const List *set, const void *data);
int         set_remove(List *set, void **data);
int         queue_enqueue(List *queue, const void *data);
int         queue_dequeue(List *queue, void **data);
int         bfs(Graph *graph, BfsVertex *start, List *hops);
void        print_array(char **arr);
int         all_digits(char **arr);
int         arr_length(char **arr);
void        check_coordinates(char *position, char *str);
void        create_path(Graph *graph, int ants_number, char *end, char *start);
void        error_handler(char *position, char  *error_msg);
int         errors(char *room);
void        get_links(char **arr, list_elmt **head);
char        *get_position(char **arr, char *position);
void        get_rooms(char **arr, list_elmt **rooms);
Graph       *graph_alloc(void);
list_elmt   *link_alloc(void);
List        *list_alloc(void);
int         match(const void *data1, const void *data2);
void        move_ants(Path *path, int ants);
int         get_number_of_ants(char **str);
void        path_init(Path *path);
int         path_ins_next(Path *path, path_elmt *element, const void *data);
int         path_rem_next(Path *path, path_elmt *element, void **data);
void        path_destroy(Path *path);
void        print_list(List *list);
void        print_array(char **arr);
void        print_graph(Graph *graph);
void	    print_out(char *ant_name, char *room);
char        *read_input(void);
void        store_link(char *str, list_elmt **head);
void        free_array(char **arr);
void        free_list_elmt(list_elmt *head);

#define queue_init list_init
#define queue_destroy list_destroy
#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)
#define queue_size list_size
#define graph_adjlists(graph) ((graph)->adjlists)
#define graph_vcount(graph) ((graph)->vcount)
#define graph_ecount(graph) ((graph)->ecount)
#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#define path_size(path) ((path)->size)
#define path_head(path) ((path)->head)
#define path_next(element) ((element)->next)
#define path_prev(element) ((element)->prev)
#define path_tail(path) ((path)->tail)
#define set_size(set) ((set)->size)

#endif