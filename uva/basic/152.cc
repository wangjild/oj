#include<stdio.h>
#include<math.h>

typedef struct node_t {
    int l, w, h;
}node;

int dis(node a, node b)
{
    return (int)(sqrt( (double)((a.l-b.l)*(a.l-b.l)+(a.h-b.h)*(a.h-b.h) + (a.w-b.w)*(a.w-b.w))  ) + 5e-6);
}

int main()
{
    int i, j, k, count[10]={0};
    int min, d;
    node tree[5000];
    i=0;
    scanf("%d%d%d", &tree[i].l,&tree[i].w,&tree[i].h);
    while(tree[i].l||tree[i].h||tree[i].w)
    {
        i++;
        scanf("%d%d%d", &tree[i].l,&tree[i].w,&tree[i].h);
    }
    for (k=0; k<i; k++)
    {
        min=1000;
        for (j=0; j<i; j++)
        {
            d=dis(tree[k],tree[j]);
            if (min > d && k!=j)
                min=d;
        }
        if (min>=0 && min<=9)
            count[min]++;
    }
    for (i=0; i<10; i++)
    {
        printf("%4d", count[i]);
    }
    printf("\n");
    return 0;
}
