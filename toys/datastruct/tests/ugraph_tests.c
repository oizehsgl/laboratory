// cflags: lnklist.c varray.c vaheap.c exception.c ugraph.c

#include <stdio.h>

#include "../ugraph.h"

void print_node(gnode* n, void* usr)
{
    int* i = (int*) n->data;
    printf("%d ", *i);
}

#define print_ll(l) { \
    for(ll_iter i = l->head; !ll_is_end(i); i = i->next) \
        print_node(*(gnode**)(i->data), NULL); \
    putchar('\n'); \
}

int main()
{
    /*
     *     0-12--1
     *  10/|    /
     *   / |   13    
     *  2--+--/---9--,3
     *     7 /   ,--`/
     *     |/,-5`   /11
     *     4`      5
     */

    ugraph* g = g_create(int);
    gnode* nodes[6];
    int c;
    nodes[0] = g_add_node(g, (c = 0, &c));
    nodes[1] = g_add_node(g, (c = 1, &c));
    nodes[2] = g_add_node(g, (c = 2, &c));
    nodes[3] = g_add_node(g, (c = 3, &c));
    nodes[4] = g_add_node(g, (c = 4, &c));
    nodes[5] = g_add_node(g, (c = 5, &c));

    g_connect(g, nodes[0], nodes[1], 12);
    g_connect(g, nodes[0], nodes[2], 10);
    g_connect(g, nodes[0], nodes[4], 7 );
    g_connect(g, nodes[1], nodes[4], 13);
    g_connect(g, nodes[2], nodes[3], 9 );
    g_connect(g, nodes[3], nodes[4], 5 );
    g_connect(g, nodes[3], nodes[5], 11);

    g_dfs(g, nodes[0], print_node, NULL); putchar('\n');
    g_dfs(g, nodes[3], print_node, NULL); putchar('\n');


    //////////////////////////////////// Dijkstra's Algo
    lnklist* path;

    path = ll_create(gnode*);
    printf("%d: ", g_dijkstra(g, nodes[0], nodes[5], path));
    print_ll(path);
    ll_destroy(path);

    path = ll_create(gnode*);
    printf("%d: ", g_dijkstra(g, nodes[1], nodes[3], path));
    print_ll(path);
    ll_destroy(path);


    //////////////////////////////////// Kruskal's Algo
    ugraph* spantree = g_create(gnode*);
    g_kruskal(g, spantree);

    for(ll_iter i = spantree->edges->head; !ll_is_end(i); i = i->next) {
        gedge* e = (gedge*)i->data;
        print_node(*(gnode**)e->head->data, NULL);
        printf("- ");
        print_node(*(gnode**)e->tail->data, NULL);
        printf(": %d\n", e->weight);
    }

    g_destroy(g);
}

