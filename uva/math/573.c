#include<stdio.h>

int main() {
    double H, U, D, F;
    while(scanf("%lf%lf%lf%lf", &H, &U, &D, &F) == 4 && H) {
        double p = 0, loss = U*F/100;
        int day;
        for(day = 1; ; day++) {
            if(U > 0) p += U;
            U -= loss;
            if(p > H) { printf("success on day %d\n", day); break; }
            p -= D;
            if(p < 0) { printf("failure on day %d\n", day); break; }
        }
    }
    return 0;
}
