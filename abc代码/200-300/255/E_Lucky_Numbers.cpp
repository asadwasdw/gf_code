#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N],b[N],c[N];
map<int,int>mp;

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=2;i<=n;i++)c[i] = a[i-1] - c[i-1];
    int ans =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t = b[j] - c[i];               
            if(i&1)t=-t;
            mp[t]++;
            ans=max(mp[t],ans);
        }
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