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
        sign = false;
        memset(s, 0, sizeof(s)); len = 1;
    }

    BigInt operator = (const char* num) {
        len = strlen(num);
        sign = (num[0] == '-');
        for (int i = 0; i < len - sign; ++i) {
            s[i] = num[len - i - 1] - '0';
        }
        len -= sign;
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

    void delPreZero()
    {
        while ( !s[len - 1] && len - 1 ) len --;
        if (sign && len == 1 && s[0] == 0)
            sign = false;
    }

    string str() const {
        string res = "";
        for (int i = 0; i < len; ++i) res = (char) (s[i] + '0') + res;
        if (res == "") res = "0";

        if (sign) res = "-" + res;
        return res;
    }

    BigInt abs(const BigInt &a) const{
        BigInt ans = a; ans.sign = false; return ans;
    }

    friend istream& operator >> (istream& in, BigInt &x) {
        string s;
        in >> s;
        x = s.c_str();
        return in;
    }

    friend ostream& operator << (ostream& out, const BigInt& x) {
        out << x.str();
        return out;
    }

    bool operator < (const BigInt& b) const {
        if (sign > b.sign)
            return true;
        if (sign < b.sign)
            return false;
        if (sign && b.sign)
            return abs(*this) < abs(b);

        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] != b.s[i]) return s[i] < b.s[i];
        }
        return false;
    } 

    bool operator > (const BigInt& b) const {
        return b < *this;
    }

    bool operator <= (const BigInt& b) const {
        return !(b < *this);
    }

    bool operator >= (const BigInt& b) const {
        return !(*this < b);
    }

    bool operator != (const BigInt& b) const {
        return b < *this || *this < b;
    }

    bool operator == (const BigInt& b) const {
        return !(b < *this) && !(*this < b);
    }

    BigInt operator - () const {
        BigInt ans = *this;
        ans.sign = !sign;
        return ans;
    }

    BigInt operator + (const BigInt& b) {
        if (sign ^ b.sign) {
            if (sign)
                return abs(b) - abs(*this);
            return abs(*this) - abs(b);
        }

        if (sign && b.sign)
            return - (abs(*this) + abs(b));

        BigInt c(0);
        c.len = 0;
        for (int i = 0, g = 0; g || i < max(len, b.len); ++i) {
            int x = g;
            if (i < len) x += s[i];
            if (i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    BigInt operator - (const BigInt& b) const {
        if (sign ^ b.sign) {
            if (sign) {
                return - (abs(*this) + abs(b));
            }
            return abs(*this) + abs(b);
        }

        if (sign && b.sign) 
            return abs(b) - abs(*this);

        if (*this < b) {
            return - (abs(b) - abs(*this));
        }

        BigInt ans;
        ans.len = max(len, b.len);
        for (int i = 0; i < ans.len; ++i) {
            ans.s[i] = s[i] - b.s[i];
        }

        for (int i = 1; i < ans.len; ++i) {
            ans.s[i] -= ans.s[i-1] < 0, ans.s[i-1] += (ans.s[i-1] < 0) * 10;
        }
        ans.delPreZero();
        return ans;
    }

    BigInt operator * (const BigInt &b) const {
        BigInt ans;
        ans.len = len + b.len;
        ans.sign = sign ^ b.sign;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < b.len; ++j) {
                ans.s[i+j] += s[i] * b.s[j];
            }

        }
        for (int i = 1; i < ans.len + 1; ++i) {
            ans.s[i] += ans.s[i-1] / 10, ans.s[i-1] %= 10;
        }
        ans.delPreZero();
        return ans;
    }

    BigInt operator * (int num) const {
        BigInt bnum(num);
        return (*this) * bnum;
    }

    BigInt operator / (const BigInt& b) {
        BigInt ans, last = 0;
        ans.sign = sign ^ b.sign;
        ans.len = len;
        for (int i = len - 1; i >= 0; --i) {
            last = last * 10 + s[i];
            int k;
            for (k = 0; k < 9; ++k)
                if (abs(b) * k <= last && abs(b) * (k + 1) > last)
                    break;
            ans.s[i] = k;
            last = last - abs(b) * k;
        }

        ans.delPreZero();
        return ans;
    }

    BigInt operator % (const BigInt &b)
    {
        if ( b == 0 || b == 1 )
            return 0;
        if ( b == 2 )
            return s[0] & 1;
        if ( sign )
            return -(abs(*this) % b);
        if ( !sign && b.sign )
            return *this % abs(b);
        return *this - ((*this / b) * b);
    }


    BigInt operator -= (const BigInt &b) {
        return *this = *this - b;
    }
};

int main() {
    char str1[256], str2[256];
    char op;
    while (scanf("%s %c %s", str1, &op, str2) != EOF) {
        BigInt a(str1), b(str2);
        if (op == '/') {
            cout << a / b << endl;
        } else {
            cout << a % b << endl;
        }
    }
     
}
