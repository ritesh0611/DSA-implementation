#include<stdio.h>
#include<stdlib.h>

bst * Search(bst *, int)

int main()
{
    return 0;
}

bst * Search(bst * r, int d)
{
    if(r->v == d)
    {
        return r;
    }
    else if(d < r->v)
    {
        Search(r->lc, d);
    }
    else
    {
        Search(r->rc, d);
    }
}
