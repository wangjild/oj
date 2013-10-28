#include<stdio.h>
int main()
{
    int n,m,test=0;
    while (scanf("%d%d",&n,&m)==2)
    {
        if (n==0) break;
        printf("CASE# %d:\n",++test);
        int i,x,a[10001]={0},b[10001]={0};
        for (i=1;i<=n;i++) {scanf("%d",&x);a[x]++;}
        for (i=1;i<=10000;i++) b[i]=b[i-1]+a[i];
        for (i=1;i<=m;i++) 
        {
            scanf("%d",&x);
            if (a[x]==0) printf("%d not found\n",x);
            else printf("%d found at %d\n",x,b[x-1]+1);
        }
    }
    return 0;
}

