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

void    list_init(List *list, void (*destroy)(void *data));
void    list_destroy(List *list);
int     list_ins_next(List *list, list_elmt *element, const void *data);
int     list_rem_next(List *list, list_elmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif