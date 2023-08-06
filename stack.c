#include<stdio.h>
#include<stdlib.h>

int size, max;
int * push(int * a, int d)
{
    a[size] = d;
    size++;
    return a;
}
void pop()
{
    size--;
}
int top(int * a)
{
    return a[size - 1];
}
int empty()
{
    if(size == 0)
        return 1;
    return 0;
}

int main()
{
    size = 0;
    max = 1000;

    int * stack;
    stack = (int *) malloc (sizeof (int) * max);

    free(stack);

    return 0;
}