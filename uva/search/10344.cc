#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

char op[3] = {'+', '-', '*'};

int data[5];

bool found = false;

void dfs(int i, int res) {
    if (found)
        return ;
    if (i == 5)
    {
        if (res == 23)
            found = true;
        return ;
    }
    dfs(i + 1, res + data[i]);
    dfs(i + 1, res - data[i]);
    dfs(i + 1, res * data[i]); 
}

int main() {

    while (scanf("%d%d%d%d%d", &data[0], &data[1], &data[2], 
                &data[3], &data[4])) {
        if (data[0] == 0)
            break;
        sort(data, data+5);    
        found = false;
        do {
            dfs(1, data[0]);
        } while (!found && next_permutation(data, data + 5));

        if (!found){
            printf("Impossible\n");
        } else {
            printf("Possible\n");
        }
    }
    return 0;
}
