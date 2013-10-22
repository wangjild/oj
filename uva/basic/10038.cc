#include <cstdio>

long abs(long a) {
    a < 0 ? (0 - a) : a;
}

using namespace std;

bool jolly(bool a[],long n)
{
    for(long i=1;i<=n-1;i++)
        if(!a[i]) return false;
    return true;
}

int main()
{
    const long maxn=3007;
    long n,a[maxn];
    bool vis[maxn];
    while(scanf("%ld",&n)==1)
    {
        for(long i=1;i<=n;i++) scanf("%ld",&a[i]);
        //  Read In
        for(long i=1;i<=n;i++) vis[i]=false;
        //  Clear
        for(long i=1;i<=n-1;i++)
        {
            long t = abs(a[i+1]-a[i]);
            if(t<=n-1) vis[t]=true;
        }
        if(jolly(vis,n)) printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}

