#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define int long long 

void solve()
{
    int n,m;
    cin>>n>>m;
    int ans1=0;
    int ans2=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;cin>>t;
            if(t=='#')ans1++;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;cin>>t;
           // cout<<t<<endl;
            if(t=='#')ans2++;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;

    if(ans1==ans2)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


}


signed main()
{
  
 solve();
}