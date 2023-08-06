#include<stdio.h>
#include<stdlib.h>

typedef struct node_ll
{
  int v;
  struct node * ptr;
}ll;

typedef struct node_q
{
  ll * front, * rear;
}q;

ll * int_ll(int);
q * enq(q *, int);
q * deq(q *);
void print(q *);

int main()
{
  q * head;
  head = (q *) malloc (sizeof (q));
  head->front = head->rear = NULL;
  
  return 0;
}

ll * int_ll(int d)
{
  ll * new;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->ptr = NULL;
}

q * enq(q * h, int d)
{
  if(h->front == NULL)
  {
    h->front = h->rear = int_ll(d);
  }
  else
  {
    h->rear->ptr = int_ll(d);
    h->rear = h->rear->ptr;
  }
  return h;
}

q * deq(q * h)
{
  ll * tmp;
  tmp = (ll *) malloc (sizeof (ll));
  tmp = h->front;
  h->front = h->front->ptr;
  free(tmp);
  return h;
}






