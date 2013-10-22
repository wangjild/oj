#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n , m;
double r[10];//用来存储每一个圆的半径
double p[10];//存储圆的横坐标
double ans;

//求解第k个圆的横坐标函数（也就是说，第k个圆很可能跟前面任何一个圆相切。这时，只要把各种情况得到取值全部算出，并把最大值 记录下来）
//我们知道对于从左往右的所有的圆来说，圆心的横坐标都是增大，不用考虑圆的大小，那么对于k这个圆，它是最右边的那么我们找到最大的横坐标才是它的横坐标值
double Point(int k){
    double R = 0;
    for(int j = 1 ; j < k ; j++){
        double tempr = p[j] + 2.0*sqrt(r[k]*r[j]);//两个圆的距离 d = sqrt((r1+r2)^2 - (r1-r2)^2) 那么有 d  =  2.0*sqrt(r[k]*r[j]);    
        if(R < tempr)//更新为最大
            R = tempr;
    }
    return R;
}

//计算当前的圆排列的长度
//p[i]-r[i],就是该圆最左边的切线的横坐标   p[i]+r[i]就是该圆最右边的切线的横坐标，那么对于这个圆排列的长度就是最右边的横坐标减去最左边的横坐标
void Distance(){
    double high , low;
    high = 0 ; low = 0;
    for(int i = 1 ; i <= m ; i++){
        if(p[i]-r[i] < low)  low  = p[i] - r[i];     //更新最左边的位置
        if(p[i]+r[i] > high) high = p[i] + r[i]; //更新最右边的位置
    }
    if(high - low < ans)
        ans = high - low;//更新最小距离
}

//回溯搜索函数
void dfs(int k){
    if(k > m)//圆放完后就是计算这个排列的长度
        Distance();
    else{
        for(int j = k ; j <= m ; j++){
            swap(r[k] , r[j]);//考虑放入k后,序列长度; 还要考虑继第k个球之后,余下的m-k个球放入后,对整个序列的长度的影响.
            double R = Point(k);
            if(R+r[k]+r[1] < ans){//满足条件继续递归
                p[k] = R;
                dfs(k+1);
            }
            swap(r[k] , r[j]);//现场的恢复
        }
    }
}

//主函数
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%d" , &m);
        memset(r , 0.0 , sizeof(r));
        memset(p , 0.0 , sizeof(p));
        for(int i = 1 ; i <= m ; i++)
            scanf("%lf" , &r[i]);
        p[1] = 0.0;//规定第一个点的横坐标为0
        ans = 999999999;
        dfs(1);
        printf("%.3lf\n" , ans);//输出的格式
    }
    return 0;
}
