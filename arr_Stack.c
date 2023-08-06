#include<stdio.h>
#include<stdlib.h>


int sz;
int empty();
int top(int *);
int * push(int *, int);
void pop(int *);
void print(int *);


int main()
{
  int max;
  scanf("%d", &max);
  sz = 0;
  int * stack;
  stack = (int *) malloc (max * sizeof(int));


  free(stack);
  return 0;
}

int empty()
{
  if(sz = 0)
  {
    return 1;
  }
  return 0;
}

int top(int * s)
{
  if(sz != 0)
  {
    return s[sz - 1];
  }
}

int * push(int * s, int d)
{
  s[sz] = d;
  sz++;
  return s;
}

void pop(int * s)
{
  sz--;
}

void print(int * s)
{
  for(int i = 0; i < sz; i++)
  {
    printf("%d ", s[i]);
  }
  printf("\n");
}

















