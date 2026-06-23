#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{
    int n,ans,q,p;
    cin>>n>>p>>q;
    ans=p;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ans=min(ans,q+x);
        
    }

    cout<<ans<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}