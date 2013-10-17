#include<stdio.h>
#include<math.h>
long f(double a,double limit)
{
    long re=1;
    while(a!=1&&a<=limit)
    {
        if(fmod(a,2)==1)
        {
            a=3*a+1;
            if(a>limit) break;
        }
        else a/=2;
        re++;
    }
    return re;
}
int main()
{
    double a,limit;
    long num=0;
    while(scanf("%lf%lf",&a,&limit)==2)
    {
        if(a==-1&&limit==-1) break;
        num++;
        printf("Case %ld: A = %.0lf, limit = %.0lf, number of terms = %ld\n",num,a,limit,f(a,limit));
    }
    return 0;
}
