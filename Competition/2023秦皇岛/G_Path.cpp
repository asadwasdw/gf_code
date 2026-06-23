#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

#define int long long
int a[N],b[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    int ans = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        // cout<<a[i]<<endl;
        if(i!=1)ans+=abs(a[i]-a[i-1]);
    }
    
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(i!=1)ans+=abs(b[i]-b[i-1]);
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