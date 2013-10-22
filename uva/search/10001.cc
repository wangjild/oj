#include<stdio.h>
#include<string.h>
int a[40],f[10],A[40],n;
int d[10][3]={{0,0,0},{0,0,1},{0,1,0},
    {0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
char b[40];
int dfs(int cur)
{
    int i,j;
    if(cur==n-1||cur==n)
    {
        for(i=0;i<8;i++)
            if(f[i]==a[cur]&&d[i][0]==A[cur-1]&&d[i][1]==A[cur]&&d[i][2]==A[cur+1])
            {
                if(cur==n-1&&!dfs(cur+1))
                    return 0;
                else
                    return 1;
            }
    }
    else
    {
        for(i=0;i<8;i++)
            if(f[i]==a[cur]&&d[i][0]==A[cur-1]&&d[i][1]==A[cur])
            {
                A[cur+1]=d[i][2];
                if(dfs(cur+1))
                    return 1;
            }
    }
    return 0;
}
int main()
{
    int i,j,k,id,ok;
    while(scanf("%d%d%s",&id,&n,b+1)==3)
    {
        for(i=1;i<=n;i++)
            a[i]=b[i]-'0';
        k=id;
        for(i=0;i<8;i++)
        {
            f[i]=k%2;
            k/=2;
        }
        ok=1;
        for(i=0;i<8;i++)
            if(a[1]==f[i])
            {
                A[0]=d[i][0];
                A[1]=d[i][1];
                A[2]=d[i][2];
                A[n]=A[0];
                A[n+1]=A[1];
                if(dfs(2))
                {
                    ok=0;
                    break;
                }
            }
        if(ok)
            printf("GARDEN OF EDEN\n");
        else
            printf("REACHABLE\n");
    }
    return 0;    
}
