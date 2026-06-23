#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
map<char,int>mp;

int main()
{   
    int n;cin>>n;

    string s;
    cin>>s;
    s=" "+s;
    int i=1;
    char a,b,c;
    a=b=c='?';
    for(;i<=n;i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]>=5){
            a=s[i];
            break;
        }
    }
    i++;
    mp.clear();
   for(;i<=n;i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]>=7){
            b=s[i];
            break;
        }
    }

    i++;
    mp.clear();
   for(;i<=n;i++)
    {
        mp[s[i]]++;
        if(mp[s[i]]>=5){
            c=s[i];
            break;
        }
    }

    if(a=='?'||b=='?'||c=='?'){
        cout<<"none"<<endl;
    }
    else{
       
        for(int i=1;i<=5;i++)cout<<a;
         for(int i=1;i<=7;i++)cout<<b;
          for(int i=1;i<=5;i++)cout<<c;
    }


}