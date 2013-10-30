#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int T,k,n,ans,s;
int main()
{
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        if(t) printf("\n");
        scanf("%d",&k);
        if(!k){ printf("3\n"); continue; }
        k=abs(k);
        n=(int)sqrt(k<<1);
        s=n*(n+1)>>1;
        while(true)
        {
            if(s>=k) break;
            n++;
            s+=n;
        }
        while((s-k)&1)
        {
            n++;
            s+=n;
        }
        printf("%d\n",n);
    }
    return 0;
}
