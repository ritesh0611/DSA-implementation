#include<stdio.h>
#include<stdlib.h>

typedef struct node_ll
{
  int v;
  struct node * prev, * next;
}ll;
typedef struct node_dq
{
  ll * front, * rear;
}dq;

dq * ins_front(dq *, int);
dq * ins_rear(dq *, int);
dq * del_front(dq *);
dq * del_rear(dq *);
void print(dq *);

////////////////////////////////////////////////////////////////////
int main()
{
  dq * head;
  head = (dq *) malloc (sizeof(dq));
  head->front = head->rear = NULL;
  return 0;
}
/////////////////////////////////////////////////////////////////////

dq * ins_front(dq * h, int d)
{
  ll * new;
  new = (ll *) malloc (sizeof(ll));
  new->v = d;
  if(h->front == NULL)
  {
    new->prev = new->next = NULL;
    h->front = h->rear = new;
  }
  else
  {
    new->next = h->front;
    new->prev = NULL;
    h->front->prev = new;
    h->front = h->front->prev;
  }
  return h;
}

dq * ins_rear(dq * h, int d)
{
  ll * new;
  new = (ll *) malloc (sizeof(ll));
  new->v = d;
  if(h->front == NULL)
  {
    new->prev = new->next = NULL;
    h->front= h->rear = new;
  }
  else
  {
    h->rear->next = new;
    new->prev = h->rear;
    new->next = NULL;
    h->rear = h->rear->next;
  }
  return h;
}

dq * del_front(dq * h)
{
  if(h->front != NULL)
  {
    ll * temp;
    temp = (ll *) malloc (sizeof(ll));
    temp = h->front;
    h->front = h->front->next;
    h->front->prev = NULL;
    free(temp);
    return h;
  }
}

dq * del_rear(dq * h)
{
  if(h->front != NULL)
  {
    ll * temp;
    temp = (ll *) malloc (sizeof (ll));
    temp = h->rear;
    h->rear = h->rear->prev;
    h->rear->next =NULL;
    free(temp);
    return h;
  }
}

void print(dq * h)
{
  ll * temp;
  temp = (ll *) malloc (sizeof (ll));
  temp = h->front;
  while(temp != NULL)
  {
    printf("%d ", temp->v);
    temp = temp->next;
  }
}

