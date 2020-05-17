/****************************
---------- list.h -----------
*****************************/

#ifndef LIST_H
#define LIST_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

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
    int             hops;
}                   BfsVertex;

/* Public interface */
void    graph_init(Graph *graph, int (*match)(const void *key1, const void *key2), void (*destroy)(Graph *data));
void    graph_destroy(Graph *graph);
void    list_init(List *list, void (*destroy)(void *data));
void    list_destroy(List *list);
int     graph_ins_vertex(Graph *graph, const void *data);
int     graph_ins_edge(Graph *graph, const void *data1, const void *data2);
int     graph_rem_vertex(Graph *graph, void **data);
int     graph_rem_edge(Graph *graph, void *data1, void **data2);
int     graph_adjlist(const Graph *graph, const void *data, adj_list **adjlist);
int     graph_is_adjacent(const Graph *graph, const void *data1, const void *data2);
int     list_ins_next(List *list, list_elmt *element, const void *data);
int     list_rem_next(List *list, list_elmt *element, void **data);
void    set_init(List *set, int (*match)(const void *key1, const void *key2), void (*destroy)(void *data));
int     set_insert(List *set, const void *data);
int     set_is_member(const List *set, const void *data);
int     set_remove(List *set, void **data);
int     queue_enqueue(List *queue, const void *data);
int     queue_dequeue(List *queue, void **data);
int     bfs(Graph *graph, BfsVertex *start, List *hops);

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
#define set_size(set) ((set)->size)

#endif