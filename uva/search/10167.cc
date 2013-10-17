#include <stdio.h>
#include <string>

using namespace std;

const int MAX = 100;
struct point {double x,y;};
point p[MAX];

double t[MAX];

void solve(int n,int &a, int &b)
{
    for(int i=-500; i<=500; i++)
        for(int k=-500; k<=500; k++)
        {
            if( i == k && k == 0 ) continue;
            int cnt = 0;
            for(int j=0; j<n; j++)
            {
                if( i*p[j].x + k*p[j].y == 0 )
                {
                    cnt = 0;
                    break;
                }
                if( i*p[j].x + k*p[j].y > 0 )
                    cnt++;
            }
            if( cnt == n/2 )
            {
                a = i;
                b = k;
                return ;
            }
        }
}

int main()
{
    int n;

    while( ~scanf("%d", &n) && n )
    {
        int sum = n;
        n *= 2;
        for(int i=0; i<n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        int a,b;
        solve(n, a, b);
        printf("%d %d\n",a, b);
    }

    return 0;
}

