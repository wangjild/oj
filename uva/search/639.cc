#include<stdio.h>
#define MAX 8
char map[MAX][MAX],n;
int vis[MAX][MAX];            //数组开大一点，最外层相当于围了一层墙，不可以放棋子
int ok_place(int i,int j){
    int left,up;
    for(left=j-1;left>=0;left--){
        if(vis[i][left]==-1)     
            break;         //左边有墙，可以放
        if(vis[i][left]==0)  //有子
            return 0;
    }
    for(up=i-1;up>=0;up--){
        if(vis[up][j]==-1)
            break;           //上面有墙
        if(vis[up][j]==0)
            return 0;        //上面有子
    }
    return 1;
}
int dfs(int i,int j,int m){               //i行，j列
    int count=0,max=0;
    while(i<m){
        if(vis[i][j]&&(vis[i][j]!=-1)&&ok_place(i,j)){
            vis[i][j]=0;          //表示已经放子了
            count=dfs(i,j+1,m)+1;
            if(max<count)
                max=count;
            vis[i][j]=1;          //恢复到未回溯前的状态
        }
        if(j>=m-1){                //采用从左到又的方式放子，所以判断是否可以放的时候也只要向左和向上判断
            i++;                   //放到了最左边应该换一行了
            j=0;
        }
        else
            j++;
    }
    return max;
}
int main()
{
    int i,j,maxsum;
    while(scanf("%d",&n)!=EOF&&n){
        for(i=0;i<n;i++){
            scanf("%s",map[i]);
            for(j=0;j<n;j++){
                if(map[i][j]=='X')
                    vis[i][j]=-1;         //-1代表有墙
                else
                    vis[i][j]=1;          //1是代表可以放子
            }
        }
        maxsum=0;
        maxsum=dfs(0,0,n);
        printf("%d\n",maxsum);
    }
    return 0;
}
