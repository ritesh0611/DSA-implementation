#include <stdio.h>
#include <stdlib.h>

int n;
int bin_srch(int * a, int strt, int end, int d)
{
    int mid;
    while(end >= strt)
    {
        mid = (strt + end) / 2;
        if(a[mid] == d)
            return mid;
        else if(a[mid] > d)
            strt = mid + 1;
        else
            end = mid - 1;
    }
}
void print (int * arr)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int * arr, i;
    scanf("%d", &n);
    arr = (int *) malloc (sizeof (int) * n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int srch;
    scanf("%d", &srch);
    printf("%d\n", bin_srch(arr, 0, n-1, srch));
    return 0;
}
