#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int d[N];
int n,m;
int ans= 0;
int low[N];
int dfn;

int h[N],e[N],ne[N],st[N],idx;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}



void dfs(int u)
{
    low[u]=++dfn;

    for(int i = h[u];~i;i=ne[i])
    {
        int v = e[i];

        if(st[i])continue;
        st[i]=st[i^1]=1;
        if(!low[v])dfs(v);
        low[u]=min(low[v],low[u]);
    }
}



void solve()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;

        add(a,b);
        add(b,a);

        edg[a].push_back(b);
        edg[b].push_back(a);

        
    }
    
    dfs(1);
    
    for(int i=1;i<=n;i++)
    {
        for(auto v:edg[i])
        {
            if(low[i]!=low[v])
            {
                d[low[i]]++;
            }
        }
    }
    
    for(int i=1;i<=n;i++)if(d[i]==1)ans++;



    cout<<(ans+1)/2<<endl;
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