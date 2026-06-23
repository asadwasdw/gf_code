#include<iostream>
#include<algorithm>

#define int long long 
using namespace std;


signed main()
{
    int n,l,r;
    cin>>n>>l>>r;
    int ans=0;
   
    while(n--)
    {
        int x;cin>>x;

        ans^=x%(r+l)/l;
        //cout<<x/r<<endl;
    }
   // cout<<ans<<endl;
    if(!ans)cout<<"Second";
    else cout<<"First";
}