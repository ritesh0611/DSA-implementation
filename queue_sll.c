#include <stdio.h>
#include <stdlib.h>

typedef struct node_ll
{
    int v;
    struct node * ptr;
}ll;
typedef struct node_q
{
    ll * front, * rear;
}queue;
ll * int2nodell(int d)
{
    ll * new;
    new = (ll *) malloc(sizeof (ll));
    new->v = d;
    new->ptr = NULL;
    return new;
}
queue * enqueue(queue * h, int d)
{
    if(h->rear == NULL)
        h->front = h->rear = int2nodell(d);
    else
    {
        h->rear->ptr = int2nodell(d);
        h->rear = h->rear->ptr;
    }
    return h;
}
queue * deq(queue * h)
{
    if(h->front != NULL && h->front != h->rear)
    {
        ll * tmp;
        tmp = h->front;
        h->front = h->front->ptr;
        free(tmp);
    }
    return h;
}
int main()
{
    return 0;
}