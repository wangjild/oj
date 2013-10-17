#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int kMaxp(17);
const int kMaxn(107);

bool cmp(const bitset<kMaxp> &a,const bitset<kMaxp> &b)
{
    return (a.to_ulong()<b.to_ulong());
}

int p,n,ans;
bitset<kMaxp> r[kMaxn];
bitset<kMaxp> used,t[kMaxn];

bool OK()
{
    for(int i=1;i<n;i++)
        if(t[i]==t[i+1])
            return false;
    return true;
}

void dfs(int depth)
{
    if(depth>p)
    {
        for(int i=1;i<=n;i++)
            t[i]=r[i];
        for(int i=1;i<=n;i++)
            t[i]=t[i]&used;
        sort(t+1,t+n+1,cmp);
        if(OK())
            ans=min(ans,(int)used.count());
        return;
    }
    dfs(depth+1);
    used[depth]=1;
    dfs(depth+1);
    used[depth]=0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&p,&n);
        for(int i=1;i<=n;i++)
            r[i].reset();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=p;j++)
            {
                int t;
                scanf("%d",&t);
                r[i][j]=t;
            }

        ans=315;
        used.reset();
        dfs(1);

        printf("%d\n",ans);
    }

    return 0;
}
