#include<iostream>
using namespace std;
const int Max = 11;
 
int n, sum, num[Max], C[Max];
bool vis[Max], flag;
 
int find_C(int a, int n){    //  求aCn。
    int i = 1, ans = 1;
    while(i <= a){
        ans = ans * n / i;
        n --; i ++;
    }
    return ans;
}
 
void dfs(int dep, int val){   //  dep为深度，val为当前的总和。
    if(val > sum) return;
    if(dep == n){
        if(val == sum && !flag){
            flag = true;
            for(int i = 0; i < n; i ++)
                cout << num[i] << ' ';
            cout << endl;
        }
        return;
    }
    for(int v = 1; v <= n && !flag; v ++)
        if(!vis[v]){
            num[dep] = v;     //  底边的各个数不能相同。
            vis[v] = true;
            dfs(dep + 1, val + C[dep] * v);
            vis[v] = false;
        }
}
 
int main(){
    int i;
    cin >> n >> sum;
    for(i = 0; i < n; i ++)
        C[i] = find_C(i, n - 1); 
    dfs(0, 0);
    return 0;
}
