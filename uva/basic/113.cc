#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
    long begin=0, end=1000000000;
    double n, p;
    while(scanf("%lf%lf", &n, &p) != EOF)
    {
        begin = 0;
        end = 1000000000;
        while( begin < end)
        {
            long mid = (long) (begin+end)/2;
            if(pow(mid, n) < p) begin = mid;
            else if(pow(mid, n) > p) end = mid;
            else if(pow(mid, n) == p)
            {
                printf("%ld\n", mid);
                break;
            }
        }
    }
    return 0;
}
