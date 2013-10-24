#include<stdio.h>
#include<stdlib.h>

#define MAX 2147483647

int main() {
    char num1[600], num2[600];
    char ch;
    double n1, n2;
    while(scanf("%s %c %s", num1, &ch, num2) != EOF) {
        printf("%s %c %s\n", num1, ch, num2);
        n1 = atof(num1);
        n2 = atof(num2);
        if(n1 > MAX)
            printf("first number too big\n");
        if(n2 > MAX)
            printf("second number too big\n");
        if(ch == '+' && n1+n2 > MAX)
            printf("result too big\n");
        if(ch == '*' && n1*n2 > MAX)
            printf("result too big\n");
    }
    return 0;
}
