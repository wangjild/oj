#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
    int n, s;
    int i;
    char str[40];
    while(cin >> str, strcmp(str, "0"))
    {
        s=0;
        n=strlen(str);
        for (i=0; i<n; i++)
        {
            s+=(str[i]-'0')*(pow(2, n-i)-1);
        }
        cout << s << endl;
    }
    return 0;
}
