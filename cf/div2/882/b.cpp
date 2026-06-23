#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;





void solve()
{

    int n;cin>>n;
    int cnt = 0;
    ll x = (1ll<<33) -1; 
    //cout<<x<<endl;

    ll t=(1ll<<33) -1;
    for(int i=1;i<=n;i++)
    {
        ll y;
        cin>>y;
        x&=y;
        t&=y;
        //out<<t<<" ";
        if(x==0)
        {
            cnt++;
            x=(1ll<<33) -1;
        }
    }
    

   // cout<<endl;


    cout<<max(1,cnt)<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}