#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int v;
  struct node * ptr;
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
  for(int i = 0; i < 10; i++)
  {
    head = ins_beg(head, 2*i);
    print(head);
  }
  for(int i = 0; i < 0; i++)
  {
    head = del_end(head);
    print(head);
  }
  head = ins_k(head, 400, 3);
  print(head);
  head = del_k(head, 5);
  print(head);
  head = del_key(head, 0);
  print(head);
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
    tmp = tmp->ptr;
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
  new->ptr = NULL;
  return new;
}

ll * ins_beg(ll * h, int d)
{
  ll * new, * tmp;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->ptr = h;
  h = new;
  return h;
}

ll * ins_end(ll * h, int d)
{
  ll * new;
  new = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->ptr = NULL;
  if(h == NULL)
  {
    h = new;
  }
  else if(h->ptr == NULL)
  {
    h->ptr = new;
  }
  else
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof (ll));
    tmp = h;
    while(tmp->ptr !=NULL)
    {
      tmp = tmp->ptr;
    }
    tmp->ptr = new;
  }
  return h;
}

ll * ins_k(ll * h, int d, int k)
{
  ll * new, * tmp;
  new = (ll *) malloc (sizeof (ll));
  tmp = (ll *) malloc (sizeof (ll));
  new->v = d;
  new->ptr = NULL;
  tmp = h;
  int count = 0;
  while(count < k - 2 && tmp != NULL)
  {
    tmp = tmp->ptr;
    count++;
  }
  new->ptr = tmp->ptr->ptr;
  tmp->ptr = new;
  return h;
}

ll * del_beg(ll * h)
{
  if(h != NULL)
  {
    ll * tmp;
    tmp = (ll *) malloc (sizeof (ll));
    tmp = h;
    h = h->ptr;
    free(tmp);
    return h;
  }
}

ll * del_end(ll * h)
{
  if(h != NULL)
  {
    ll * tmp1;
    tmp1 = (ll *) malloc (sizeof (ll));
    tmp1 = h;
    if(h->ptr == NULL)
    {
      tmp1 = h->ptr;
      free(tmp1);
      h = NULL;
    }
    else if(h->ptr->ptr == NULL)
    {
      tmp1 = h->ptr;
      free(tmp1);
      h->ptr = NULL;
    }
    else
    {
      ll * tmp;
      tmp = (ll *) malloc (sizeof (ll));
      tmp = h;
      while(tmp->ptr->ptr !=NULL)
      {
        tmp = tmp->ptr;
      }
      tmp1 = tmp->ptr;
      free(tmp1);
      tmp->ptr = NULL;
    }
    return h;
  }
}

ll * del_k(ll * h, int k)
{
  ll * tmp, *tmp1;
  tmp = (ll *) malloc (sizeof (ll));
  tmp1 = (ll *) malloc (sizeof (ll));
  tmp = h;
  int count = 0;
  while(count < k - 2 && tmp != NULL)
  {
    tmp = tmp->ptr;
    count++;
  }
  tmp1 = tmp->ptr;
  tmp->ptr = tmp->ptr->ptr;
  free(tmp1);
  return h;
}

ll * del_key(ll * h, int d)
{
  ll * tmp, * tmp1;
  tmp = (ll *) malloc (sizeof (ll));
  tmp1 = (ll *) malloc (sizeof (ll));
  if(h->v == d)
  {
    tmp = h;
    h = h->ptr;
    free(tmp);
  }
  else if(h->ptr->v == d)
  {
    tmp = h->ptr;
    h->ptr = h->ptr->ptr;
    free(tmp);
  }
  else 
  {
    tmp = h;
    while(tmp->ptr->v != d && tmp != NULL)
    {
      tmp = tmp->ptr;
    }
    tmp1 = tmp->ptr;
    tmp->ptr = tmp->ptr->ptr;
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
    tmp = tmp->ptr;
  }
  printf("\n");
}

