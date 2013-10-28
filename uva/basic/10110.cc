#include<stdio.h>
#include<math.h>

int main()
{
    long long n;///注意数据范围
    long long m;
    
    for (n = 1; n < 1000000; ++n)
    {
        m = (long long) sqrt(n);
        puts(m * m == n ? "yes" : "no");
    }
    return 0;
}

