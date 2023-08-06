#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v;
    struct node * lc, * rc;
}bst;

bst *  int2node (int d)
{
    bst * new;
    new = (bst *) malloc (sizeof (bst));
    new->v = d;
    new->lc = new->rc = NULL;
    return new;
}
bst * bnr_src(bst * r, int d)
{
    if(d == r->v)
        return r;
    else if (d < r->v)
        bnr_src(r->lc, d);
    else
        bnr_src(r->rc, d);
}
bst * insrt (bst * r, int d) {
    if (r == NULL)
        r = int2node(d);
    else if (d < r->v)
        r->lc = insrt(r->lc, d);
    else
        r->rc = insrt(r->rc, d);
    return r;
}
bst * dlt(bst * r, int d)
{
    if(r->v == d)
    {
        if(r->lc == NULL && r->rc == NULL)
            return NULL;
        else if (r->lc == NULL)
            return r->rc;
        else if (r->rc == NULL)
            return r->lc;
        else
        {
            bst * tmp;
            tmp = r->rc;
            while (tmp->lc->lc != NULL)
                tmp = tmp->lc;
            bst * min;
            min = tmp->lc;
            tmp->lc = NULL;
            min->lc = r->lc;
            min->rc = r->rc;
            return min;
        }
    }
    else if(r->v > d)
        r->lc = dlt(r->lc, d);
    else
        r->rc = dlt(r->rc, d);
    return r;
}
void inordr (bst * r)
{
    if(r != NULL)
    {
        inordr(r->lc);
        printf("%d ", r->v);
        inordr(r->rc);
    }
}
void prordr (bst * r)
{
    if(r != NULL)
    {
        printf("%d ", r->v);
        prordr(r->lc);
        prordr(r->rc);
    }
}
void pstordr (bst * r)
{
    if(r != NULL)
    {
        pstordr(r->lc);
        pstordr(r->rc);
        printf("%d ", r->v);
    }
}
bst * clsst_nsstr (bst * r, bst * min, bst * max)
{
    if(r->v >= min->v && r->v <= max->v)
        return r;
    else if(r->v > min->v)
        clsst_nsstr(r->lc, min, max);
    else if(r->v < max->v)
        clsst_nsstr(r->rc, min, max);
}
int dist (bst * r, bst * d)
{
    int i = 0;
    bst * tmp;
    tmp = (bst *) malloc (sizeof (bst));
    tmp = r;
    while(tmp->v != d->v)
    {
        if(d->v < tmp->v)
        {
            tmp = tmp->lc;
            i++;
        }
        else
        {
            tmp = tmp->rc;
            i++;
        }
    }
    return i;
}
int dist2node(bst * r, bst * i, bst * j)
{
    return (dist(r, i) + dist(r, j) - 2 * (dist(r, clsst_nsstr(r, i, j))));
}

typedef struct node_ll
{
    bst * b;
    struct node * ptr;
}ll;
typedef struct node_q
{
    ll * front, * rear;
}queue;
ll * nodebst2nodell(bst * r)
{
    ll * new;
    new = (ll *) malloc(sizeof (ll));
    new->b = r;
    new->ptr = NULL;
    return new;
}
queue * enq(queue * h, bst * r)
{
    if(r != NULL)
    {
        if(h->front == NULL)
            h->front = h->rear = nodebst2nodell(r);
        else
        {
            h->rear->ptr = nodebst2nodell(r);
            h->rear = h->rear->ptr;
        }
    }
    return h;
}
queue * deq(queue * h)
{
    if(h->front != NULL)
    {
        ll *tmp;
        tmp = h->front;
        h->front = h->front->ptr;
        free(tmp);
    }
    return h;
}
void bfs(queue * h, bst * r)
{
    if(r != NULL && h->front == NULL)
        h = enq(h, r);
    if(h->rear != NULL)
    {
        printf("%d ", h->front->b->v);
        h = enq(h, h->front->b->lc);
        h = enq(h, h->front->b->rc);
        h = deq(h);
        if(h->front != NULL)
            bfs(h, h->front->b);
    }
}


int main()
{
    bst * root;
    root = (bst *) malloc(sizeof (bst));
    root = NULL;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int d;
        scanf("%d", &d);
        root = insrt(root, d);
    }
    printf("\ninorder=>");
    inordr(root);
    printf("\nbfs=>");

    queue * head;
    head = (queue *) malloc(sizeof (queue));
    head->front = head->rear = NULL;

    bfs(head, root);
    free(root);
    return 0;
}