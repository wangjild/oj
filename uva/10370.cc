#include<stdio.h>
int main(){
    int n,i,f,s,t,a[1001];
    float p;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&f);
        s=0;
        for(i=0;i<f;i++){
            scanf("%d",&a[i]);
            s=s+a[i];}  
        s=s/f;           
        t=0;
        for(i=0;i<f;i++)
            if(a[i]>s) ++t;   
        p=100.0*t/f;  
        printf("%.3f%%\n",p);
    }
}
