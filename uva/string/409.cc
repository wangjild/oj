#include<stdio.h>
#include<string.h>

char keyword[100][100];
int n, m;

int search(char str[])
{
    int i, k, slen=strlen(str);
    char s[100];
    int j=0, count=0;
    for (i=0; i<slen; i++)
    {
        if (str[i]>='a' && str[i] <= 'z')
        {
            s[j]=str[i];
            j++;
        }
        else
        {
            s[j]=0;
            j=0;
            for (k=0; k<n; k++)
            {
                if (!strcmp(s, keyword[k]))
                    count++;
            }
        }
    }
    return count;
}

int main()
{
    int i, count[100], num=1, max, j, slen;
    char str[100], s[100][100];
    while(scanf("%d%d%*c", &n, &m) != EOF)
    {
        for (i=0; i<n; i++)
        {
            gets(keyword[i]);
            for (j=0; j<strlen(keyword[i]); j++)
                if (keyword[i][j] >= 'A' && keyword[i][j] <='Z')
                    keyword[i][j]+=32;
        }
        for (i=0; i<m; i++)
        {
            gets(str);
            slen=strlen(str);
            strcpy(s[i], str);
            for (j=0; j<slen; j++)
                if (str[j] >='A' && str[j] <='Z')
                    str[j]+=32;
            count[i]=search(str);
        }
        printf("Excuse Set #%d\n", num);
        num++;
        max=0;
        for (i=0; i<m; i++)
            if (max <= count[i])
                max=count[i];
        for (i=0; i<m; i++)
            if (max == count[i])
                puts(s[i]);
        printf("\n");
    }
    return 0;
}
