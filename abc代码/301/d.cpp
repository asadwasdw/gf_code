#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;

#define int long long




signed main()
{
   string s;
   cin>>s;

   long long n;
   cin>>n;
   

   int res=0;

    //reverse(s.begin(),ans.end());



    for(int i=0;i<s.size();i++)
    {
        int j=s.size()-i-1;
        int t=1LL<<j;

        if(s[i]=='1')res+=t;

    }

    //cout<<res<<endl;

    for(int i=0;i<s.size();i++)
    {
        int j=s.size()-i-1;
        int t=1LL<<j;

        if(s[i]=='?')
        {
            if(res+t<=n){
                s[i]='1';
                res+=t;
            }
        }
    }

    if(res>n)cout<<"-1";
    else 
   cout<<res<<endl;
}