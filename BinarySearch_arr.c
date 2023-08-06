#include<stdio.h>
#include<stdlib.h>

int bin_rec(int *, int, int, int);
int bin_itr(int *, int);

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", bin_rec(arr, arr[3], 0, n));
    return 0;
}

// recursive
int bin_rec(int * a, int d, int strt, int end)
{
    int mid = (strt + end) / 2;
    if(a[mid] == d)
    {
        return mid;
    }
    else if(d < a[mid])
    {
        bin_rec(a, d, strt, mid - 1);
    } 
    else
    {
        bin_rec(a, d, mid + 1, end);
    }
}

// iterative
int bin_itr(int * a, int d)
{
}
