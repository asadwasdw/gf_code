#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
int Q;
PII root;



struct query{
    int a,b;
    int ans=-1;
}q[N];


void dfs(int u,int fa,int dep)
{
   // cout<<u<<" "<<fa<<" "<<dep<<endl;

    if(dep>root.second){
        root.first=u;
        root.second=dep;
    }

    for(auto t:edg[u]){
        if(t==fa)continue;
        dfs(t,u,dep+1);
    }
}

int fa[N][20];

void dfs1(int u,int father)
{
    fa[u][0]=father;
    
    for(int i=1;i<20;i++)
    {
        fa[u][i]=fa[fa[u][i-1]][i-1];
    }

    for(auto v:edg[u]){
        if(v==father)continue;
        dfs1(v,u);
    }
}

int find(int a,int k)
{
    for(int i=19;i>=0;i--)
    {

        int t = (1ll<<i);
        // cout<<t<<endl;
        // cout<<a<<" "<<fa[a][i]<<endl;
        if(k>=t){
            k-=t;
            a=fa[a][i];
        }
    }
    if(a)return a;
    else return -1;
}

void js()
{
    for(int i=1;i<=Q;i++)
    {
        if(q[i].ans==-1)q[i].ans = find(q[i].a,q[i].b);
    }
}





void solve()
{
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    cin>>Q;

    for(int i=1;i<=Q;i++)cin>>q[i].a>>q[i].b;

    dfs(1,0,0);
    dfs1(root.first,0);
    js();
    root.second=0;
    dfs(root.first,0,0);
    dfs1(root.first,0);
    js();

   for(int i=1;i<=Q;i++)cout<<q[i].ans<<endl;
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