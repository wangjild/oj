#include <cstdio>
#include <cstring>

#define MAX_N 25

char sqr[MAX_N][MAX_N];

int W, H;
int x, y;

int solve(int x, int y) {
    int sum = 0;
    if (sqr[x][y] == '.') {
        sum += 1;
        sqr[x][y] = '@';
    }
    // left
    if (sqr[x-1][y] == '.') {
        sum += solve(x-1, y);
    }
    // right
    if (sqr[x+1][y] == '.') {
        sum += solve(x+1, y);
    }
    // up
    if (sqr[x][y-1] == '.') {
        sum += solve(x, y-1);
    }
    // down
    if (sqr[x][y+1] == '.') {
        sum += solve(x, y+1);
    }

    return sum;
}

int main() {

    memset(sqr, '#', sizeof(char) * MAX_N * MAX_N);
    while (scanf("%d%d", &W, &H), getchar(), !(W == 0 && H == 0)) {
        for (int i = 1; i <= H; ++i) {
            for (int j = 1; j <= W + 1; ++j) {
                char c = getchar();
                if (c != '\n')
                    sqr[i][j] = c;
                if (c == '@') {
                    x = i;
                    y = j;
                }
            }
            sqr[i][W+1] = '#';
        }
        for(int j = 1; j <= W+1; ++j) {
            sqr[H+1][j] = '#';
        }

        /*
        for(int i = 0; i <= H+1; ++i) {
            for(int j = 0; j <= W+1; ++j) {
                printf("%c", sqr[i][j]);
            }
            printf("\n");
        }*/

        printf("%d\n", solve(x, y) + 1);
    }

    return 0;
}
