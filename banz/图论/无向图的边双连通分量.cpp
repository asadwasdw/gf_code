#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>E(N);

int dfn[N],low[N],tim;
stack<int>stk;
int dcc_cnt,id[N];

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tim;
    stk.push(u);

    for(auto v:E[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=fa)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        dcc_cnt++;
        while(1)
        {
            int v = stk.top();stk.pop();
            id[v] = dcc_cnt;
            if(u==v)break;
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }

    tarjan(1,-1);




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