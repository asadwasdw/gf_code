#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
int f[N];
ll cnt[N];

void dfs(int u,int fa)
{
    f[u]=fa;
    cnt[u]=1;
    for(auto v:edg[u]){
        if(v==fa)continue;
        dfs(v,u);
        cnt[u]+=cnt[v];
    }
    // cout<<u<<endl;
    // for(int i=1;i<=n;i++)cout<<cnt[i]<<" ";cout<<endl;
}

void solve()
{

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    

    dfs(1,0);
    ll ans = (n)*(n-2)*(n-1)/6;
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        //cout<<cnt[i]<<endl;
        ll c = 0;
        for(auto t :edg[i]){
            if(t==f[i])continue;
            c+=1ll*cnt[t]*(cnt[i]-cnt[t]-1);
        }
        c/=2;
        c+=(cnt[i]-1)*(n-cnt[i]);
        ans-=c;
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