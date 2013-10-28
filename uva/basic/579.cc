#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void)
{
    char s[10]="";
    int h, m;
    double angle;
    while(fgets(s, 10, stdin)!=NULL)
    {
        sscanf(s,"%d:%d", &h, &m);
        if(h==0 && m==0) break;
        angle = fabs (6*m-((double) m / 2 + h * 30));
        if(360 - angle < angle)
            angle = 360 - angle;
        printf("%.3lf\n", (floor( angle * 1000 + 0.5)) / 1000);
    }
    return 0;
}
