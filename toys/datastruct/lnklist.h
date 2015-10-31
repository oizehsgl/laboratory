#ifndef LNKLIST_H_INCLUDED
#define LNKLIST_H_INCLUDED

#include <stddef.h>

typedef struct lnklist_node_t_ {
    unsigned char* data;
    struct lnklist_node_t_* next;
    struct lnklist_node_t_* prev;
} lnklist_node, *ll_iter;

typedef struct lnklist_t_ {
    size_t elem_size;
    lnklist_node* head;
    lnklist_node* tail;
} lnklist;

lnklist* ll_create_(size_t szelem);
void ll_destroy(lnklist* ll);
size_t ll_length(const lnklist* ll);

void ll_insert(lnklist* ll, size_t pos, void* data);
void ll_insert_bef(lnklist* ll, ll_iter iter, void* data);
void ll_prepend(lnklist* ll, void* data);
void ll_append(lnklist* ll, void* data);
void ll_remove(lnklist* ll, ll_iter i);

ll_iter ll_iter_at(lnklist* ll, size_t pos);
void* ll_at(lnklist* ll, size_t pos);
int ll_is_end(const ll_iter n);

#define ll_create(type) ll_create_(sizeof(type))

#endif // LNKLIST_H_INCLUDED
