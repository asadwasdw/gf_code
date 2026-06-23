#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int a[N];

void solve()
{
    int n;cin>>n;
    int ans =0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=1)ans+=max(a[i],a[i-1]);
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