#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <istream>
#include <ostream>

using namespace std;

const int maxn = 3000;

struct bign {
    int len, s[maxn];
    bign() { memset(s, 0, sizeof(s)); len = 1;}
    
    bign operator = (const char* num) {
        len = strlen(num);
        for (int i = 0; i < len; ++i) s[i] = num[len - i - 1] - '0';
        return *this;
    }

    bign operator = (int num) {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    bign(int num) { *this = num; }
    bign(const char* num) { *this = num; }

    string str() const {
        string res = "";
        for (int i = 0; i < len; ++i) res = (char) (s[i] + '0') + res;
        if (res == "") res = "0";
        return res;
    }

    friend istream& operator >> (istream& in, bign &x) {
        string s;
        in >> s;
        x = s.c_str();
        return in;
    }

    friend ostream& operator << (ostream& out, const bign& x) {
        out << x.str();
        return out;
    }

    bign operator + (const bign& b) const {
        bign c; c.len = 0;
        for (int i = 0, g = 0; g || i < max(len, b.len); ++i) {
            int x = g;
            if (i < len) x += s[i];
            if (i < b.len) x += b.s[i];
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    bign operator * (const bign& b) const {
        bign c; c.len = 0;
        for (int i = 0; i < len; ++i) {
            int j = 0, g = 0;
            for (; j < b.len; ++j) {
                int m = b.s[j] * s[i] + g;
                c.s[i+j] += m % 10;
                if (c.s[i+j] > 9) {
                    g = 1; c.s[i+j] -= 10;
                } else {
                    g = 0;
                }
                g += m / 10;
            }
            if (g) {
                c.s[b.len + i] += g;
            }
        }

        c.len = len + b.len;
        int i;
        for (i = c.len - 1; i >= 0; --i) {
            if (c.s[i] != 0)
                break;
        }
        if (i == -1) {
            c.s[i] = 0; c.len = 1;
        } else {
            c.len = i + 1;
        }
        return c;
    }

    bign operator += (const bign& b) {
        *this = *this + b;
        return *this;
    }

    bool operator < (const bign& b) const {
        if (len != b.len) return len < b.len;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] != b.s[i]) return s[i] < b.s[i];
            return false;
        }
    }

    bool operator > (const bign& b) const {
        return b < *this;
    }

    bool operator <= (const bign& b) const {
        return !(b < *this);
    }

    bool operator >= (const bign& b) const {
        return !(*this < b);
    }

    bool operator != (const bign& b) const {
        return b < *this || *this < b; 
    }

    bool operator == (const bign& b) const {
        return !(b < *this) && !(*this < b);
    }
};

int main () {

    char str1[256];
    char str2[256];
    while (scanf("%s%s", str1, str2) != EOF) {
        bign a(str1), b(str2);
        cout << a * b << endl;
    }
    return 0;
}
