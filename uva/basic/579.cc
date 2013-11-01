#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    int h, m;
    double sum;
    while(scanf("%d:%d", &h, &m) && (h||m))
    {
        if (h == 12)
            h=0;
        sum=(h*30.0+m*1.0/2)-m*6.0;
        if (sum < 0)
            sum=-sum;
        if (sum > 180)
            sum=360-sum;
        printf("%.3f\n", sum);
    }
    return 0;
}
