#include<stdio.h>
#include<stdlib.h>

int * swap(int *, int, int);
int * heapify(int *, int);
int * construct(int *, int);
void print(int *, int);

int main()
{
    int n, * arr;
    scanf("%d", &n); 
    arr = (int *) calloc (n, sizeof(int));
    for(int i = 0; i < n; i++)
    { 
        scanf("%d", &arr[i]);
    }
    //print(arr, n);
    arr = construct(arr, n);
    print(arr, n);
    free(arr);
    return 0;
  }

int * swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}

int * heapify(int * a, int d)
{
    int lc_ind = 2 * d + 1;
    int rc_ind = 2 * d + 2;
    int larger = d;
    if(a[lc_ind] > a[larger])
    {
        larger = lc_ind;
    }
    if(a[rc_ind] > a[larger])
    {
        larger = rc_ind;
    }
    if(larger != d)
    {
        a = swap(a, larger, d);
        heapify(a, larger);
    }
    
    return a;
}

int * construct(int * a, int d)
{
    for(int i = d/2; i >= 0; i--)
    {
        a = heapify(a, i);
    }
    return a;
}

void print(int * a, int d)
{
    for(int i = 0; i < d; i++)
    {
        printf("%d ", a[i]); 
    }
    printf("\n");
}
