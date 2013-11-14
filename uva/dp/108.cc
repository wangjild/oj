#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 102;
int arr[N][N];

int PS[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) 
            scanf("%d", &arr[i][j]);

    for (int i = 0; i <= n; ++i) 
        PS[i][0] = PS[0][i] = 0;
    

    for (int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) 
            PS[i][j] = PS[i-1][j] + PS[i][j-1] - PS[i-1][j-1] + arr[i][j];

    int ans = -128;
    for (int i_min = 1; i_min <= n; ++i_min)
        for (int i_max = i_min; i_max <= n; ++i_max)
            for (int j_min = 1; j_min <= n; ++j_min)
                for (int j_max = j_min; j_max <= n; ++j_max)
                    ans = max(ans, PS[i_max][j_max] - PS[i_min - 1][j_max] - PS[i_max][j_min - 1] + PS[i_min - 1][j_min - 1]);
            

    printf("%d\n", ans);
    return 0;
}
