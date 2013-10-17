#include <iostream>

using namespace std;

int main()
{
    char s[15];
    while(cin.getline(s, sizeof(s)))
    {
        if(s[0] == '|')
        {
            char c = 0;
            for(int i = 2; i <= 5; i++)
                if(s[i] == 'o') c = c * 2 + 1;
                else c *= 2;
            for(int i = 7; i <= 9; i++)
                if(s[i] == 'o') c = c * 2 + 1;
                else c *= 2;
            cout<<c;
        }
    }
    return 0;
}
