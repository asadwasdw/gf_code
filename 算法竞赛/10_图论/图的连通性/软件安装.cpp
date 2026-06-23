#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
 int n,m;
vector<vector<int>>edg(N);
vector<vector<int>>G(N);
int cnt = 0 ;
int low[N],num[N],dfn,scc[N];
stack<int>s;
int w[N],col[N],d[N];
int W[N],V[N];

map<PII,int>ST;
void tj(int u)
{
    s.push(u);
    ++dfn;
    low[u]=num[u]=dfn;

    for(auto v:edg[u]){
        if(!num[v]){
            tj(v);
            low[u]=min(low[v],low[u]);
        }
        else if(!scc[v]){
            low[u]=min(low[u],num[v]);
        }
    }

    if(low[u]==num[u]){

        ++cnt;
        //cout<<cnt<<" "<<u<<endl;
        while(1){
            int v = s.top();s.pop();
            scc[v]=cnt;
            W[cnt]+=w[v];
            V[cnt]+=col[v];
            //cout<<cnt<<"包含"<<v<<" "<<w[v]<<" "<<col[v]<<endl;
            if(u==v)break;
        }
    }
}
int dp[110][510];
void dfs(int u)
{
    for(int i = V[u];i<=m;i++)dp[u][i]=W[u];

    for(auto v:G[u]){

        dfs(v);

        for(int j = m-V[u];j>=0;j--){

            for(int q=0;q<=j;q++){
                dp[u][j+V[u]]=max(dp[u][j+V[u]],dp[u][j+V[u]-q]+dp[v][q]);
            }
        }
    }
}



void solve()
{
   
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>col[i];
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>d[i];
        if(d[i])
           edg[d[i]].push_back(i);
        d[i]=0;
    }

    for(int i=1;i<=n;i++){
        if(!num[i])tj(i);
    }
   //for(int i=1;i<=n;i++)cout<<i<<"在"<<scc[i]<<endl;

    for(int i=1;i<=n;i++){
        for(auto j:edg[i]){
            int x = scc[i];
            int y = scc[j];
            if(x==y)continue;
            if(ST[{x,y}])continue;
            ST[{x,y}]=1;
            G[x].push_back(y);
         //   cout<<x<<" "<<y<<endl;
            d[y]++;
        }
    }



    for(int i=1;i<=cnt;i++){
        if(!d[i]){
          //  cout<<0<<" "<<i<<endl;
            G[0].push_back(i);
        }
    }

    // for(int i=0;i<=cnt;i++){
    //     cout<<i<<"V "<<V[i]<<"W "<<W[i]<<endl;
    // }
    dfs(0);

    // for(int i=0;i<=cnt;i++)
    // {
    //     for(int j=0;j<=m;j++)cout<<dp[i][m]<<" ";cout<<endl;  
    //     cout<<endl;
    // }

    cout<<dp[0][m]<<endl;










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