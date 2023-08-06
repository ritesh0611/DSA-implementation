#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int v;
  struct node * prv, *nxt;
}ll;

int size(ll *);
int empty(ll *);
ll * int2node(int);
ll * ins_beg(ll *, int);
ll * ins_end(ll *, int);
ll * ins_k(ll *, int, int);
ll * del_beg(ll *);
ll * del_end(ll *);
ll * del_k(ll *, int);
ll * del_key(ll *, int);
void print(ll *);

///////////////////////////////////////////////////////////////////////////////////////
int main()
{
  ll * head;
  head = (ll *) malloc (sizeof (ll));
  head = NULL;

  free(head);
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////

int size(ll * h)
{
  ll * tmp;
  tmp = (ll *) malloc (sizeof (ll));
  tmp = h;
  int Size = 0;
  while(tmp != NULL)
  {
    Size++;
    tmp = tmp->nxt;
  }
  return Size;
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

ll * int2node(int d)
{
  ll * new;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->prv = new->nxt = NULL;
  return new;
}

ll * ins_beg(ll * h, int d)
{
  ll * new, * tmp;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->nxt = h;
  new->prv = NULL;
  if(h != NULL)
  {
    h->prv = new;
  }
  h = new;
  return h;
}

ll * ins_end(ll * h, int d)
{
  ll * new;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->prv = new->nxt = NULL;
  if(h == NULL)
  {
    h = new;
  }
  else if(h->nxt == NULL)
  {
    h->nxt = new;
    new->prv = h;
  }
  else
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof (ll));
    tmp = h;
    while(tmp->nxt !=NULL)
    {
      tmp = tmp->nxt;
    }
    tmp->nxt = new;
    new->prv = tmp;
  }
  return h;
}

ll * ins_k(ll * h, int d, int k)
{
  ll * new, * tmp;
  new = (ll *) malloc (sizeof (ll));
  tmp = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->nxt = new->prv = NULL;
  tmp = h;
  int count = 0;
  while(count < k - 2 && tmp != NULL)
  {
    tmp = tmp->nxt;
    count++;
  }
  new->nxt = tmp->nxt->nxt;
  tmp->nxt->nxt->prv = new;
  tmp->nxt = new;
  new->prv = tmp;
  return h;
}

ll * del_beg(ll * h)
{
  if(h != NULL)
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof (ll));
    tmp = h;
    h = h->nxt;
    h->prv = NULL;
    free(tmp);
    return h;
  }
}

ll * del_end(ll * h)
{
  if(h != NULL)
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof (ll));
    if(h->nxt == NULL)
    {
      tmp = h->nxt;
      free(tmp);
      h = NULL;
    }
    else if(h->nxt->nxt == NULL)
    {
      tmp = h->nxt;
      free(tmp);
      h->nxt = NULL;
    }
    else
    {
      ll * tmp1;
      tmp1 = (ll *) malloc (sizeof(ll));
      tmp = h;
      while(tmp->nxt->nxt !=NULL)
      {
        tmp = tmp->nxt;
      }
      tmp1 = tmp->nxt;
      free(tmp1);
      tmp->nxt = NULL;
    }
    return h;
  }
}

ll * del_k(ll * h, int k)
{
  if(h->nxt->nxt != NULL)
  {
    ll * tmp, *tmp1;
    tmp = (ll *) malloc (sizeof (ll));
    tmp1 = (ll *) malloc (sizeof (ll));
    tmp = h;
    int count = 0;
    while(count < k - 2 && tmp != NULL)
    {
      tmp = tmp->nxt;
      count++;
    }
    tmp1 = tmp->nxt;
    tmp->nxt = tmp->nxt->nxt;
    tmp->nxt->nxt->prv = tmp;
    free(tmp1);
    return h;
  }
}

ll * del_key(ll * h, int d)
{
  ll * tmp, * tmp1;
  tmp = (ll *) malloc (sizeof (ll));
  tmp1 = (ll *) malloc (sizeof (ll));
  if(h->v == d)
  {
    tmp = h;
    h = h->nxt;
    h->prv = NULL;
    free(tmp);
  }
  else if(h->nxt->v == d)
  {
    tmp = h->nxt;
    h->nxt = h->nxt->nxt;
    h->nxt->nxt->prv = h;
    free(tmp);
  }
  else 
  {
    tmp = h;
    while(tmp->nxt->v != d && tmp != NULL)
    {
      tmp = tmp->nxt;
    }
    tmp1 = tmp->nxt;
    tmp->nxt = tmp->nxt->nxt;
    tmp->nxt->nxt->prv = tmp;
    free(tmp1);
  }
  return h;
}

void print(ll * h)
{
  ll * tmp;
  tmp = (ll *) malloc (sizeof (ll));
  tmp = h;
  while(tmp != NULL)
  {
    printf("%d ", tmp->v);
    tmp = tmp->nxt;
  }
  printf("\n");
}

