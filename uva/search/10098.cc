#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[15];

int main () {
    int c;
    scanf("%d\n", &c);
    while (c--) {
        gets(str);
        int len = strlen(str);

        sort(str, str + len);

        do {
            printf("%s\n", str);
        } while(next_permutation(str, str + len));
        printf("\n");
    }

    return 0;
}
