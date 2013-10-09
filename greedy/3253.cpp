#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_NUM 20000

int a[MAX_NUM];

int main() {
    int num;

    cin>>num;

    int i;
    long long sum = 0;
    for (i = 0; i < num; ++i) 
    {
        cin >> a[i];
        sum += a[i];
    }

    sort (a, a + num);

      


    for (i = 0; i < num; ++i) 
    {
        cout << a[i];
    }
    cout<<endl;
}
