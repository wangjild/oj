#include<iostream>
#include<string>
using namespace std;

int main(){
    int round=0;
    string gWord;
    string inWord;
    cin>>round;
    //cout<<round;
    while(round!=-1){
        cin>>gWord>>inWord;
        bool wl = false;
        int c =0;
        int x =7;
        int y = 0;
        for (int i=0;i<inWord.size();i++){
            bool match = false;
            for (int j=0;j<gWord.size();j++){
                if (inWord[i]==gWord[j]){
                    c++;
                    gWord[j]='*';
                    match = true;
                }
            }
            if (!match)
                x--;
            else
                y++;
            if ((i+1-y)>6)
                break;
            if (c == gWord.size()){
                wl = true;
                break;
            }
        }
        cout<<"Round "<<round<<endl;
        if (x>0 && !wl)
            cout<<"You chickened out."<<endl;
        else if (wl)
            cout<<"You win."<<endl;
        else
            cout<<"You lose."<<endl;
        cin>>round;
    }
    return 0;
}
