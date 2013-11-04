#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d\n",n*(m-1)+n-1);
    }
}
