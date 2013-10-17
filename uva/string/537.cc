#include<stdio.h>
#include<string.h>

int main (){
    int i,j,Case,index=1;
    double P,I,U,c;
    char str[1001];
    while(scanf("%d\n",&Case) != EOF){
        while(Case--){
            P = 0;
            I = 0;
            U = 0;
            c = 1;
            gets(str);
            for(i = 0;i < strlen(str);){
                //P
                if(str[i] == 'P' && str[i+1] == '='){
                    i += 2;
                    //提取小数点前数据
                    while(str[i] >= '0' && str[i] <= '9'){
                        P = P * 10 + str[i] - '0';
                        i++;
                    }
                    //提取小数点后数据
                    if(str[i] == '.'){
                        i++;
                        while(str[i] >= '0' && str[i] <= '9'){
                            c *= 0.1; 
                            P += c * (str[i] - '0');
                            i++;
                        }
                    }
                    c = 1;
                    if(str[i] == 'k'){
                        P *= 1000;
                        i++;
                    }
                    else if(str[i] == 'm'){
                        P /= 1000;
                        i++;
                    }
                    else if(str[i] == 'M'){
                        P *= 1000000; 
                        i++;
                    }
                }
                //U
                else if(str[i] == 'U' && str[i+1] == '='){
                    i += 2;
                    //提取小数点前数据
                    while(str[i] >= '0' && str[i] <= '9'){
                        U = U * 10 + str[i] - '0';
                        i++;
                    }
                    //提取小数点后数据
                    if(str[i] == '.'){
                        i++;
                        while(str[i] >= '0' && str[i] <= '9'){
                            c *= 0.1; 
                            U += c * (str[i] - '0');
                            i++;
                        }
                    }
                    c = 1;
                    if(str[i] == 'k'){
                        U *= 1000;
                        i++;
                    }
                    else if(str[i] == 'm'){
                        U /= 1000;
                        i++;
                    }
                    else if(str[i] == 'M'){
                        U *= 1000000; 
                        i++;
                    }
                }
                //I
                else if(str[i] == 'I' && str[i+1] == '='){
                    i += 2;
                    //提取小数点前数据
                    while(str[i] >= '0' && str[i] <= '9'){
                        I = I * 10 + str[i] - '0';
                        i++;
                    }
                    //提取小数点后数据
                    if(str[i] == '.'){
                        i++;
                        while(str[i] >= '0' && str[i] <= '9'){
                            c *= 0.1; 
                            I += c * (str[i] - '0');
                            i++;
                        }
                    }
                    c = 1;
                    if(str[i] == 'k'){
                        I *= 1000;
                        i++;
                    }
                    else if(str[i] == 'm'){
                        I /= 1000;
                        i++;
                    }
                    else if(str[i] == 'M'){
                        I *= 1000000; 
                        i++;
                    }
                }
                i++;
            }
            //输出
            printf("Problem #%d\n",index);
            if(P > 0 && I > 0){
                printf("U=%.2lfV\n",P / I);
            }
            else if(P > 0 && U > 0){
                printf("I=%.2lfA\n",P / U);
            }
            else if(U > 0 && I > 0){
                printf("P=%.2lfW\n",U * I);
            }
            printf("\n");
            index++;
        }
    }
    return 0;
}

