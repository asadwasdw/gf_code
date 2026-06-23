#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n,m;
vector<vector<int>>edg(N);
vector<vector<int>>G(N);

int low[N],num[N],dfn,cnt,scc[N],w[N];
stack<int>s;

map<PII,bool>ST;


void dfs(int u)
{
    s.push(u);
    ++dfn;
    low[u]=num[u]=dfn;

    for(auto v:G[u]){
        if(v==u)continue;
        if(!num[v]){
            dfs(v);
            low[u]=min(low[v],low[u]);
        }
        else if(!scc[v]){
            low[u]=min(low[u],num[v]);
        }
    }

    if(low[u]==num[u]){
        ++cnt;
        while(1)
        {
            w[cnt]++;
            int v = s.top();s.pop();
            scc[v]=cnt;
            if(u==v)break;
        }
    }
}

int rd[N];
int dp[N];
int sum[N];


void tppx(){
    queue<int>q;
    for(int i=1;i<=cnt;i++){
        if(rd[i]==0)
        {
            q.push(i);
            dp[i]=1;
            sum[i]=w[i];
        }
    }

    while(q.size()){
        int u = q.front();q.pop();
        //cout<<u<<endl;
      
        for(auto v:edg[u]){
            rd[v]--;
            if(rd[v]==0){
                q.push(v);
            }

            if(sum[v]==sum[u]+w[v]){
                dp[v]+=dp[u];
                dp[v]%=mod;
            }
            else if(sum[u]+w[v]>sum[v]){
                dp[v]=dp[u];
                sum[v]=sum[u]+w[v];
            }
        }
    }
    
    // for(int i=1;i<=cnt;i++)cout<<w[i]<<" ";cout<<endl;
    // for(int i=1;i<=cnt;i++)cout<<dp[i]<<" ";cout<<endl;
    // for(int i=1;i<=cnt;i++)cout<<sum[i]<<" ";cout<<endl;
}

void solve()
{
    cin>>n>>m>>mod;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        if(a!=b)
        G[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!num[i])dfs(i);
    }

    // for(int i=1;i<=n;i++)cout<<scc[i]<<" ";cout<<endl;
    // for(int i=1;i<=cnt;i++)cout<<w[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++){
        for(auto t:G[i]){
            int x = scc[i];
            int y = scc[t];
            if(x==y)continue;
            if(ST[{x,y}])continue;
            ST[{x,y}]=true;
           // cout<<x<<" "<<y<<endl;
            edg[x].push_back(y);
            rd[y]++;
        }
    }

    tppx();
    int yu =0,k=0;
    for(int i=1;i<=cnt;i++){
        if(sum[i]>sum[yu]){
            yu = i ;
            k=dp[i];
        }
        else if(sum[i]==sum[yu]){
            k+=dp[i];
            k%=mod;
        }
    }
    cout<<sum[yu]<<"\n"<<k<<endl;

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