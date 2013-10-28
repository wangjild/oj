#include <cstdio>
#include <cmath>



int x, y;

int solve(int dis) {
    if (dis == 0)
        return 0;
    int x = sqrt(dis + 0.05);
    // printf("x=%d\n", x*(x+1));
    if (x * x == dis)
        return 2*x - 1;
    else if (dis <= x * (x+1))
        return 2*x;
    else 
        return 2*x + 1;
}

int main() {
    int c;
    scanf("%d", &c);

    while (c--) {
        scanf("%d %d", &x, &y);
        printf("%d\n", solve(y - x)); 
    }
}
