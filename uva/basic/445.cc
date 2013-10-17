#include <cstdio>
#include <cstring>
#include <cctype>

int main() {

    char line[2000];

    while (gets(line) != NULL) {
        int len = strlen(line); 

        int sum = 0;
        for (int i = 0; i < len; ++i) {
            if (isdigit(line[i])) {
                sum += line[i] - '0';
                continue;
            }
            if (line[i] == '!') {
                printf("\n");
                sum = 0;
                continue;
            }

            for(int j = 0; j < sum; ++j) {
                if (line[i] == 'b'){
                    printf(" ");
                }
                else
                    printf("%c", line[i]);
            }
            sum = 0;
        }
        printf("\n");
    }

    return 0;
}
