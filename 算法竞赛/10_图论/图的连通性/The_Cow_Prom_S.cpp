#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int cnt,dfn,num[N],low[N];
int sccno[N];
int ans = 0;
stack<int>s;

void dfs(int u)
{
    ++dfn;
    s.push(u);
    low[u]=num[u]=dfn;

    for(auto v:edg[u]){
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=min(low[u],num[v]);
        }
    }

    if(low[u]==num[u])
    {
        ++cnt;
        int sz=0;
        while(1)
        {
            int v=s.top();s.pop();
            sccno[v]=cnt;
            ++sz;
            if(v==u)break;
        }
        if(sz>1)ans++;
    }

    
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        edg[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        if(num[i]==0)dfs(i);
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