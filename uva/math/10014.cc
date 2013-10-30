#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int cases, n;
    double af, al, c, sum;
    cin>>cases;
    while(cases--){
        cin>>n>>af>>al;
        sum = 0;
        for(int i = 0; i < n; i++){
            cin>>c;
            sum += (n - i) * c;
        }
        printf("%0.2lf\n", (n * af + al - 2 * sum) / (n + 1));
        if(cases)    printf("\n");
    }
    return 0;
}

