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

void typx()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1){
            d[i]--;
           // cout<<i<<endl;
            q.push(i);
        }
    }

    while(q.size()){
        auto u = q.front();q.pop();
        //cout<<u<<endl;
        for(auto t:edg[u]){
            int v = t;
            if(d[v])d[v]--;
            if(d[v]==1)
                q.push(v);
            
        }
    }
}

int ans= 0;

void dfs(int u,int fa)
{
    //cout<<u<<endl;
    int ky = 1;
    if(d[u])ky=0;
    for(auto t:edg[u])
    {
        if(t==fa)continue;
        if(d[t])continue;
        dfs(t,u);
        ky=0;
    }
    //if(ky)cout<<u<<" "<<fa<<endl;
    ans+=ky;
}


void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        d[a]++;
        d[b]++;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    typx();
 

    for(int i=1;i<=n;i++){
        if(d[i]){
            dfs(i,0);
        }
    }
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