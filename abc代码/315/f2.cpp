#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;



ll qmi(ll a,ll b,ll c)
{
    ll res = 1;
    while(b)
    {
        if(b&1)res= res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res;
}


vector<vector<int>>edg(N);

int f[N],sz[N];
int ans[N];

int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];

    // if(f[x]!=x)return find(f[x]);
    // return f[x];
}


void dfs(int u,int w)
{
    ans[u]= (ans[u]+w)%mod;
    for(auto v:edg[u]){
        dfs(v,ans[u]);
    }
}


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)f[i]=i,sz[i]=1; 
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;

        int fa = find(a);
        int fb = find(b);
        
        edg[fa].push_back(fb);
        ans[fb]= (ans[fb]-ans[fa]+mod)%mod;
        ans[fa]= (ans[fa]+(sz[fa]*qmi((sz[fa]+sz[fb]),mod-2,mod)%mod))%mod;
        ans[fb]= (ans[fb]-(sz[fa]*qmi((sz[fa]+sz[fb]),mod-2,mod)%mod)+mod)%mod;
        ans[fb]= (ans[fb]+(sz[fb]*qmi((sz[fa]+sz[fb]),mod-2,mod)%mod)+mod)%mod;

       // cout<<ans[fa]<<" "<<ans[fb]<<endl;
        sz[fa]+=sz[fb];
        f[fb]=fa;

        // if(fa==3){
        //     cout<<"fa"<<ans[3]<<endl;
        // }
        // if(fb==3){
        //     cout<<"fb"<<ans[3]<<endl;
        // }
    }
    
    //for(int i=1;i<=n;i++)cout<<i<<" "<<ans[i]<<endl;


    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<f[i]<<endl;
        if(i==find(i)){
            dfs(i,0);
        }
    }

   //for(int i=1;i<=n;i++)cout<<i<<" "<<ans[i]%mod<<endl;

   for(int i=1;i<=n;i++)cout<<ans[i]<<" ";



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