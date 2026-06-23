#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int idx,h[N],e[N],ne[N],w[N];

void add(int a,int b)
{
    w[idx]=1;
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
int n,k;
int dis[N];
int pre[N];

int bfs(int u)
{
    memset(dis,0x3f,sizeof dis);
    dis[u] = 0;

    queue<int>q;
    q.push(u);

    while(q.size()){

        int t = q.front();q.pop();

        for(int i=h[t];~i;i=ne[i])
        {
            int v = e[i];
            if(dis[v]==INF)
            {
                dis[v]=dis[t]+w[i];
                pre[v] = i;
                q.push(v);
            }
        }
    }

    int ans = u;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>dis[ans])ans=i;
    }
    return ans;

}

void update(int ed,int st)
{
    while(ed!=st)
    {
        w[pre[ed]]=-1;
        w[pre[ed]^1]=-1;
        ed=e[pre[ed]^1];// 走反边回去，正边和反边的id只有最后一位不同
    }
}

int d2;
void dp(int u,int fa)
{
    for(int i=h[u];~i;i=ne[i]){
        int v = e[i];
        if(v==fa)continue;
        dp(v,u);
        d2 = max(d2,dis[u]+dis[v]+w[i]);
        dis[u]= max(dis[u],dis[v]+w[i]);
    }
}


void solve()
{
    memset(h,-1,sizeof h);

    cin>>n>>k;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }

    int p = bfs(1);
    int q = bfs(p);// dis[q]此时是直径

   // cout<<p<<" "<<q<<" "<<dis[q]<<endl;

    int ans = 2*n-2-dis[q]+1;

    if(k==2)
    {
        update(q,p);
        memset(dis,0,sizeof dis);
        dp(1,-1);
        ans -= d2 - 1;
        // int p = bfs(1);
        // int q = bfs(p);
        //ans -= dis[q]-1; 此时有负权边，不能用bfs了
        //https://blog.csdn.net/Visors/article/details/108127782
        //cout<<d2<<" "<<p<<" "<<q<<" "<<dis[q]<<endl;
    }

    cout<<ans<<"\n";
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