#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int h[N],ne[N],e[N],idx,w[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}
int dis[N];
int n,m;
int pre[N];
int bfs(int x)
{
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    q.push(x);
    dis[x]=0;

    while(q.size())
    {
        int u = q.front();q.pop();
        for(int i =h[u];~i;i=ne[i]){
            int v = e[i];
            if(dis[v]==INFll){
                pre[v] = i;
                dis[v] = dis[u]+w[i];
                q.push(v);
            }
        }
    }

    int res = x;
    for(int i=1;i<=n;i++)
    {
        //cout<<i<<" "<<dis[i]<<endl; 
        if(dis[res]<dis[i])res=i;
    }
    return res;
}

vector<int>dia;
bool st[N];

void finddia(int start,int end){
    while(start!=end)
    {
        st[end]=true;
        dia.push_back(end);
        end = e[pre[end]^1];
    }
    st[end]=true;
    dia.push_back(end);
    reverse(dia.begin(),dia.end());
}


int dfs(int u,int fa)
{
    int res = 0;
    for(int i = h[u];~i;i=ne[i])
    {
        int v = e[i];
        if(v==fa)continue;
        if(st[v])continue;
        res= max(res,dfs(v,u)+w[i]);
    }
    return res;
}





void solve()
{
    memset(h,-1,sizeof h);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    int p = bfs(1);
    int q = bfs(p);
    finddia(p,q);
   // cout<<p<<" "<<q<<endl;
    //for(auto t:dia)cout<<t<<" ";cout<<endl;
    int ans = 0;
    for(auto t:dia)
    {
        int T = dfs(t,-1)+min(dis[q]-dis[t],dis[t]);
        ans =max(ans,T);
    }
    cout<<ans+dis[q]<<endl;




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