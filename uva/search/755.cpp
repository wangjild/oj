#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#include<cstdlib>

int telenum[100002];

int comp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int main()
{

    int i, j, n, T, cnt, len, flag, low, sum;
    char temp[100];
    scanf("%d", &T);
    char alphalist[] = "2223334445556667777888999";
    while(T--)
    {
        scanf("%d", &n);
        for(i=0; i<n; ++i)
        {
            scanf("%s", temp);
            len = strlen(temp);
            sum = 0;
            for(j=0 ; j<len; ++j)
            {
                if('0' <= temp[j] && '9' >= temp[j])
                    sum = sum*10 + (temp[j] - '0');
                else if('A'<= temp[j] && 'Z' >= temp[j])
                    sum = sum*10 + (alphalist[temp[j]-'A']-'0');
            }
            telenum[i] = sum;
        }

        qsort(telenum, n, sizeof(int),comp);
        low = cnt = flag = 0;
        for(i=0; i<n; ++i)
        {
            if(i+1 < n && telenum[low] == telenum[i+1])
                cnt++;
            else 
            {
                if(cnt) 
                {
                    flag = 1;
                    printf("%03d-%04d %d\n", telenum[low]/10000, telenum[low]%10000, cnt+1);
                    cnt = 0;
                }
                low = i+1;
            }
        }
        if(!flag)    printf("No duplicates.\n");
        if(T) printf("\n"); 
    }

    return 0;
}
