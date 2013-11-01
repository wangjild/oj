#include <cstdio>
#include <stack>

#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)

using namespace std;

stack<char> st;

int main() {
    char c;
    while (EOF != (c = getchar())) {
        if (unlikely(c == ' ') || unlikely(c == '\n')) {
            while (!st.empty()) {
                putchar(st.top()); st.pop();
            }
            putchar (c);
            continue;
        } 
        st.push(c);
    }
    return 0;
}
