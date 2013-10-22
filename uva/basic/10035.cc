#include <iostream>
    
using namespace std;
    
int main(int ac, char *av[])
{
    int first, second;
    
    while (cin >> first >> second, first || second)
    {
        int carry = 0;
        int counter = 0;
        while (first && second)
        {
            carry = (((first % 10 + second % 10 + carry) > 9) ? 1 : 0);
            counter += carry;
            first /= 10;
            second /= 10;
        }
        
        while (first)
        {
            carry = ((first % 10 + carry > 9) ? 1 : 0);
            counter += carry;
            first /= 10;
        }
        
        while (second)
        {
            carry = ((second % 10 + carry > 9) ? 1 : 0);
            counter += carry;
            second /= 10;       
        }
        
        if (counter > 1)
            cout << counter << " carry operations." << endl;
        else if (counter == 1)
            cout << "1 carry operation." << endl;
        else
            cout << "No carry operation." << endl;
    }
    
    return 0;
}
