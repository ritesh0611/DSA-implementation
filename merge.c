#include <stdio.h>
#include <stdlib.h>

int * swap(int * a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
    return a;
}
void print(int * a, int d)
{
    int i;
    for(i = 0; i < d; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int * merge(int * a, int strt, int mid, int end)
{
//    printf("%d %d", strt, end);
    int i, j, k, * suba1, * suba2;
    suba1 = (int *) malloc((mid - strt + 1) * sizeof (int));
    for(int i = 0; i <= mid - strt; i++)
        suba1[i] = a[i];
    suba2 = (int *) malloc((end - mid + 2) * sizeof (int));
    for(int i = 0; i <= end - mid + 1; i++)
        suba2[i] = a[mid + i + 1];
    k = 0, i = strt, j = mid + 1;
    while ((i <= mid || j <= end) && k <= end)
    {
//        printf("a[i] = %d a[j] = %d ==> k = %d  i = %d j = %d (strt %d & end=%d && mid%d) =>", a[i], a[j], k, i, j, strt, end, mid);
        if ((suba1[i] <= suba2[j] && i <= mid) || j > end)
        {
            a[k] = suba1[i];
//            printf("a[%d] = %d", k, a[k]);
            i++;
        }
        else if((a[j] <= a[i] && j <= end) || i > mid)
        {
            a[k] = suba2[j];
//            printf("merged[%d] = %d", k, merged[k]);
            j++;
        }
        k++;
    }/*
    printf("--merged--");
    print(merged, end - strt + 1);
    printf("\n");*/
    return a;
}
int * mergesort(int * a, int strt, int end)
{

    if(strt < end)
    {
        printf("before =>");
        print(a, end -strt + 1);
        int mid;
        mid = (strt + end) / 2;
        a = mergesort(a, strt, mid);
        a = mergesort(a, mid + 1, end);
        return merge(a, strt, mid, end);
    }
}


int main() {
    int n, * arr, i;
    arr = (int *) malloc(sizeof (int));
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    arr = mergesort(arr, 0, n - 1);
    print(arr, n);

//    free(arr);
    return 0;
}
