#include<stdio.h>
#include<string.h>
#define VALUE 8
int chess[VALUE+1][VALUE+1];
int visit[VALUE+1];
int blackslash[VALUE*2], slash[VALUE*2];
int value;

void Traverse(int cur, int sum, int num)
{
    int i, j;
    if(cur >= VALUE)
    {
        if(num == VALUE && value < sum)
            value = sum;
        return; 
    }
    for(i=0; i<VALUE; ++i)
    {
        if(!visit[i] && !blackslash[i-cur+VALUE-1] && !slash[2*(VALUE-1)-i-cur])
        {
            visit[i] = blackslash[i-cur+VALUE-1] = slash[2*(VALUE-1)-i-cur] = 1;
            Traverse(cur+1, sum+chess[cur][i], num+1);
            visit[i] = blackslash[i-cur+VALUE-1] = slash[2*(VALUE-1)-i-cur] = 0;
        }
    }
    return;
}

int main()
{
    int i, j, k;
    scanf("%d", &k);
    while(k--)
    {
        for(i=0; i<VALUE; ++i)
            for(j=0; j<VALUE; ++j)
                scanf("%d", &chess[i][j]);
        value = 0;
        memset(blackslash, 0, sizeof(blackslash));
        memset(slash, 0, sizeof(slash));        
        memset(visit, 0, sizeof(visit));
        Traverse(0, 0, 0);
        printf("%5d\n", value);
    }
    return 0;
}
