#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
vector<vector<int>>edg(N+1);


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;

        edg[a].push_back(b);
        edg[b].push_back(a);

    }

    queue<int>q;
    q.push(1);
    vector<int>dis(n+1,-1);
    dis[1]=0;
    vector<int>fa(n+1);
    vector<int>inner(n+1);

    while(q.size())
    {
        int u = q.front();q.pop();
        for(auto v:edg[u]){
            if(dis[v]!=-1)continue;
            dis[v]=dis[u]+1;
            fa[v]=u;
            q.push(v);
            inner[u]=1;//当前点是树边上的点
        }
    }
    ll ans =1;
    for(int u=2;u<=n;u++)
    {
        if(dis[u]==-1||dis[u]>k)continue;
        ll cnt = 0;//非树边
        for(auto v:edg[u]){
            if(fa[v]==u||fa[u]==v)continue;//去掉树边
            cnt++;
        }
        if(!inner[u]){//当前点是非树边，所以可以在来的路上加
            cnt=max(1ll,cnt);
        }
        ans+=1+cnt*(k-dis[u]);
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