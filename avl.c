#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int v, ht;
    struct node * lc, * rc;
}avl;

int max(int i, int j)
{
    if(i >= j)
        return i;
    return j;
}
avl * int2node(int d)
{
    avl * new;
    new = (avl *) malloc(sizeof (avl));
    new->v = d;
    new->ht = 1;
    new->lc = new->rc = NULL;
    return new;
}
int height(avl * r)
{
    if(r == NULL)
        return 0;
    return (max(height(r->lc), height(r->rc)) + 1);
}
int bal_fac(avl * r)
{
    if(r->rc == NULL && r->lc == NULL)
        return 0;
    else if(r->lc == NULL)
        return height(r->rc);
    else if(r->rc == NULL)
        return -height(r->lc);
    return (height(r->rc) - height(r->lc));
}
avl * ll(avl * r)
{
    avl * tmp;
    tmp = r->rc;
    r->rc = r->rc->lc;
    tmp->lc = r;
    tmp->ht = height(tmp);
    r = tmp;
    r->ht = height(r);
    return r;
}
avl * rr(avl * r)
{
    avl * tmp;
    tmp = r->lc;
    r->lc = r->lc->rc;
    tmp->rc = r;
    tmp->ht = height(tmp);
    r = tmp;
    r->ht = height(r);
    return r;
}
avl * lr(avl * r)
{
    r->lc = ll(r->lc);
    r = rr(r);
    return r;
}
avl * rl(avl * r)
{
    r->rc = rr(r->rc);
    r = ll(r);
    return r;
}
avl * dlt(avl *r, int d)
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
            avl * tmp;
            tmp = r->rc;
            while (tmp->lc->lc != NULL)
                tmp = tmp->lc;
            avl * min;
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
avl * insrt(avl *r, int d)
{
    if(r == NULL)
        r = int2node(d);
    else if(r->v > d)
        r->lc = insrt(r->lc, d);
    else
        r->rc = insrt(r->rc, d);
    r->ht = height(r);
    int balance = bal_fac(r);
    if(balance < -1 && d < r->lc->v)
        r = rr(r);
    else if(balance > 1 && d >= r->rc->v)
        r = ll(r);
    else if(balance > 1 && d < r->rc->v)
        r = rl(r);
    else if(balance < -1 && d >= r->lc->v)
        r = lr(r);
    return r;
}
void inordr(avl *r)
{
    if(r != NULL)
    {
        inordr(r->lc);
        printf("%d ", r->v);
        inordr(r->rc);
    }
}
void prordr(avl *r)
{
    if(r != NULL)
    {
        printf("%d ", r->v);
        prordr(r->lc);
        prordr(r->rc);
    }
}
void pstordr(avl *r)
{
    if(r != NULL)
    {
        pstordr(r->lc);
        pstordr(r->rc);
        printf("%d ", r->v);
    }
}

typedef struct node_ll
{
    avl * b;
    struct node * ptr;
}LL;
typedef struct node_q
{
    LL * front, * rear;
}queue;
LL * nodebst2nodell(avl * r)
{
    LL * new;
    new = (LL *) malloc(sizeof (LL));
    new->b = r;
    new->ptr = NULL;
    return new;
}
queue * enq(queue * h, avl *r)
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
        LL * tmp;
        tmp = h->front;
        h->front = h->front->ptr;
        free(tmp);
    }
    return h;
}
void bfs(queue * h, avl * r)
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
    avl * root;
    root = NULL;

    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        int d;
        scanf("%d", &d);
        root = insrt(root, d);
    }

    queue * head;
    head = (queue *) malloc(sizeof (queue));
    head->front = head->rear = NULL;
    bfs(head, root);
    printf("\n");

    free(root);
    return 0;
}