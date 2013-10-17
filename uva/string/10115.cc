#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i;
    string sa,a,b;
    string s[100],ss[100];
    while(cin>>n)
    {
        if(n==0)break;
        cin.ignore();
        for(i=0;i<n;i++)
        {
            getline(cin,s[i]);
            getline(cin,ss[i]);
        }
        getline(cin,sa);
        int flag;
        i=0;
        while(i<n)
        {
            flag=sa.find(s[i],0);
            if(flag!=string::npos)
                sa.replace(flag,s[i].length(),ss[i]);    
            else
            {
                i++;
            }
        }
        cout<<sa<<endl;
        sa="";
        a="";
        b="";
    }
    return 0;
}
