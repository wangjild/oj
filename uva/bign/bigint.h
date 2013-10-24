#include <algorithm>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 10010;

struct BigInt {
    bool sign;
    int s[MAXN], len;
    BigInt() {
        memset(s, 0, sizeof(s)); len = 1;
    }

    BigInt operator = (const char* num) {
        len = strlen(num);
        sign = (num[0] == '-');
        for (int i = 0; i < len - sign; ++i) {
            s[i] = num[len - i - 1] - '0';
        }
        return *this;
    }   

    BigInt operator = (int num) {
        char s[MAXN];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    BigInt(int num) { *this = num; }
    BigInt(const char* num) { *this = num; }

    string str() const {
        string res = "";
        res += sign ? "-" : ""; 
        for (int i = 0; i < len; ++i) res = (char) (s[i] + '0') + res;
        if (res == "") res = "0";
        return res;
    }
 
};

int main() {
    BigInt a("100");
    BigInt b("0");
    BigInt c("-10000000");

    cout << a.str() << " " << b.str() << " " << c.str() << endl;
    return 0;
}
