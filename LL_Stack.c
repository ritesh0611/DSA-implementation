#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int v;
  struct node * ptr;
}ll;

int size(ll *);
int empty(ll *);
ll * push(ll *, int);
ll * pop(ll *);
int top(ll *);
void print(ll *);

int main()
{
  ll * head;
  head = (ll *) malloc (sizeof(ll));
  head = NULL;


  return 0;
}

int size(ll * h)
{
  ll * tmp;
  tmp = (ll *) malloc (sizeof(ll));
  tmp = h;
  int count = 0;
  while(tmp != NULL)
  {
    count++;
    tmp = tmp->ptr;
  }
  return count;
}

int empty(ll * h)
{
  if(size(h) == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

ll * push(ll * h, int d)
{
  ll * new;
  new = (ll *) malloc (sizeof(ll));
  new->v = d;
  new->ptr = h;
  h = new;
  return h;
}

ll * pop(ll * h)
{
  if(h != NULL)
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof(ll));
    tmp = h;
    h = h->ptr;
    free(tmp);
    return h;
  }
}

int top(ll * h)
{
  if(h != NULL)
  {
    return h->v;
  }
}

void print(ll * h)
{
  ll * tmp;
  tmp = (ll *) malloc (sizeof (ll));
  tmp = h;
  while(tmp != NULL)
  {
    printf("%d ", tmp->v);
    tmp = tmp->ptr;
  }
  printf("\n");
}

