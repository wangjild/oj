#include<cstdio>
#include<cstring>

int main()
{
    int x, y, n, i, k = 1, code[1020], _code[1020], j, code1[1020];
    while(scanf("%d",&n) && n)
    {
        for(i = 0;i < n; i++)
        {
            scanf("%d",&code[i]);
            code1[i] = code[i];
        }
        int flag = 0;
        for(i = 0;i < n; i++)
        {
            scanf("%d",&_code[i]);
            if(_code[i] != 0)
                flag = 1;
        }
        printf("Game %d:\n",k++);
        while(flag)
        {
            x = 0;
            y = 0;
            for(i = 0;i < n; i++)
                if(code[i] == _code[i])
                {
                    x++;
                    _code[i] = code[i] = 0;
                }
            for(i = 0;i < n; i++)
            {
                for(j = 0;j < n; j++)
                {
                    if((code[i] == _code[j]) && _code[j])
                    {
                        _code[j] = code[i] = 0;
                        y++;
                        break;
                    }
                }
            }
            for(i = 0;i < n;i++)
                code[i] = code1[i];
            printf("    (%d,%d)\n",x,y);
            flag = 0;
            for(i = 0;i < n; i++)
            {
                scanf("%d",&_code[i]);
                if(_code[i] != 0)
                    flag = 1;
            }
        }
    }
    return 0;
}
