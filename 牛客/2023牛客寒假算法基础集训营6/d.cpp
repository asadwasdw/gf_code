#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int numu=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='u')numu++;
    }
    long long lu=0,ru=numu;
     long long  anslu=0,ansru=0;
     long long  maxd=0,ansd=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='u')
        {
            lu++;
            ru--;
        }
        if(s[i]=='d'){
            if(lu)
            {
                anslu+=ru;
            }
            if(ru)
            {
                ansru+=lu;
            }
            if(lu*ru>ansd)
            {
                ansd=lu*ru;
                maxd=i;
            }
        }
    }

    if(anslu>=ansru&&anslu>=ansd){
        for(int i=0;i<s.size();i++){
            if(s[i]=='u'){
                s[i]='a';
                break;
            }
        }
    }
    
    else if(ansru>=anslu&&ansru>=ansd){
        for(int i=s.size();i>=0;i--){
            if(s[i]=='u'){
                s[i]='a';
                break;
            }
        }
    }

    else if(ansd>=anslu&&ansd>=ansru){
        s[maxd]='a';
    }

    //cout<<anslu<<" "<<ansd<<" "<<ansru<<endl;
    cout<<s<<endl;

}