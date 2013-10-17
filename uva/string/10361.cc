#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    long n;
    cin>>n;
    getchar();
    for(long cas=1;cas<=n;cas++)
    {
        string a,b,ans;
        getline(cin,a);
        for(long i=0;a[i];i++)
            if(a[i]!='<'&&a[i]!='>')
                cout<<a[i];
        cout<<endl;
        // Print the First Line
        getline(cin,b);
        // Read In stringA and stringB

        long j,pos[5]={0};
        j=0;
        for(long i=0;a[i];i++)
            if(a[i]=='<'||a[i]=='>')
            {
                j++;
                pos[j]=i;
            }
        // Get Four Positions

        string _1="",_2="",_3="",_4="";
        for(long i=pos[1]+1;i<=pos[2]-1;i++)
            _1+=a[i];
        for(long i=pos[2]+1;i<=pos[3]-1;i++)
            _2+=a[i];
        for(long i=pos[3]+1;i<=pos[4]-1;i++)
            _3+=a[i];
        for(long i=pos[4]+1;a[i];i++)
            _4+=a[i];

        ans="";
        for(long i=0;b[i];i++)
        {
            if(b[i]!='.')
                ans+=b[i];
            else
            {
                ans+=_3+_2+_1+_4;
                break;
            }
        }
        cout<<ans<<endl;
        // Print the Secont Line
    }
    return 0;
}

