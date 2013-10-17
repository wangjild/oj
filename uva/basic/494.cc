#include <cstdio>
#include <cstring>
#include <cctype>

char ch[256];

int main() {
    while (gets(ch) != NULL) {
        int len = strlen(ch);
        int num = 0;

        bool inword = false;
        for (int i = 0; i < len; ++i) {
            if (isalpha(ch[i])) {
                inword = true;
            }
            if (!isalpha(ch[i]) || i == len - 1){
                if (inword) {
                    inword = false;
                    num ++;
                }
            }
        }

        printf("%d\n", num);
    }
}
