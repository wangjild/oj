#include<stdio.h>
#include<math.h>
int main()
{
    long n,m,t;
    while(scanf("%ld",&n)!=EOF, n)
    {
        t = sqrt(n);
        m = t * t;
        if (m == n)
            printf("yes\n");
        else
            printf("no\n"); 
    }
    return 0;
}
