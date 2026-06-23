#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int dfn,cnt;
int num[N],low[N],sccno[N];

stack<int>s;
int d[N];

void dfs(int u)
{
    s.push(u);
    low[u]=num[u]=++dfn;
    for(auto v:edg[u]){
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v])
            low[u]=min(low[u],num[v]);
    }

    if(low[u]==num[u]){
        //cout<<u<<endl;
        cnt++;
        while(1){
           
            int v = s.top();s.pop();
            sccno[v]=cnt;
            if(u==v)break;
            // cout<<v<<" ";
        }
       // cout<<"S\n";
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        if(!num[i])dfs(i);
    }

   // for(int i=1;i<=n;i++)cout<<sccno[i]<<" ";cout<<endl;

   //cout<<cnt<<endl;

    for(int i=1;i<=n;i++)
    {
        for(auto t:edg[i]){
            int x= sccno[i];
            int y = sccno[t];
            //cout<<i<<" "<<t<<endl;
            //cout<<x<<" "<<y<<endl;
            if(x==y)continue;
            d[x]++;
        }
    }



    int ans = 0;

    for(int i=1;i<=cnt;i++){
        if(d[i]==0)
        {
            if(ans==0)ans=i;
            else {
                cout<<"0";
                return;
            }
        }
    }

    int res = 0;
    for(int i=1;i<=n;i++){
        if(sccno[i]==ans)res++;
    }
    cout<<res<<endl;

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