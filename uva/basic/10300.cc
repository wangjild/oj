#include<stdio.h>
#include<math.h>
int main()
{
    long n;
    scanf("%ld",&n);
    for(long cas=1;cas<=n;cas++)
    {
       long f,size,animal,ef,ans=0;
       scanf("%ld",&f);
       for(long i=1;i<=f;i++)
       {
          scanf("%ld%ld%ld",&size,&animal,&ef);
          ans+=size*ef;
       }
       printf("%ld\n",ans);
    }
return 0;
}

