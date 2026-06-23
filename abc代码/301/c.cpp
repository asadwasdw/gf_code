#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

map<char,int>st1;
map<char,int>st2;

signed main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;

    int num1=0;
    int num2=0;

    for(auto a:s)
    {
        
        if(a=='@')num1++;
        else st1[a]++;
    }

    for(auto a:t)
    {
        
        if(a=='@')num2++;
        else st2[a]++;
    }
    
    bool ky=true;

    for(int i=0;i<=25;i++)
    {
        char T=(char)(i+'a');
        //cout<<T<<endl;

        if(T=='a'||T=='t'||T=='c'||T=='o'||T=='d'||T=='e'||T=='r')
        {
            if(st1[T]>st2[T])
            {
                num2+=(st2[T]-st1[T]);
            }
            else 
            {
                num1+=(st1[T]-st2[T]);
            }

            if(num1<0||num2<0)ky=false;
        }
        else 
        {
            if(st1[T]!=st2[T])
            {
                ky=false;
            }
        }
    }

    if(ky)cout<<"Yes";
    else cout<<"No";
    
}