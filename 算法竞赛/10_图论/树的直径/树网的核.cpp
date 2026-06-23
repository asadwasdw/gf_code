#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10,M=2*N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n,s;
int sum = 0;

int h[N],ne[M],idx,w[M],e[M];
int pre[N];

void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dis[N];

int bfs(int u)
{
    memset(dis,-1,sizeof dis);
    dis[u]=0;
    queue<int>q;
    q.push(u);

    while(q.size())
    {
        auto x = q.front();q.pop();
        for(int i=h[x];~i;i=ne[i])
        {
            int y = e[i];
            if(dis[y]==-1)
            {
                dis[y]=dis[x]+w[i];
                q.push(y);
                pre[y]=i;
            }
        }
    }

    int ans = u;
    for(int i=1;i<=n;i++){
       // cout<<i<<" "<<dis[i]<<endl;
        if(dis[i]>dis[ans])ans=i;
    }
    return ans;
}
int q,p;

vector<int>zj;


void qzj(int ed,int st)
{
    while(ed!=st)
    {
        zj.push_back(ed);
        ed=e[(pre[ed]^1)];
    }
    zj.push_back(st);
    reverse(zj.begin(),zj.end());
}

int d[N];
int st[N];

int bfs2(int u)
{
    int res = 0;
    queue<int>q;
    q.push(u);

    while(q.size())
    {
        int x = q.front();q.pop();
        for(int i = h[x];~i;i=ne[i])
        {
            int j = e[i];

            if(d[j]==-1)
            {
                d[j]=d[x]+w[i];
                res = max(d[j],res);
                q.push(j);
            }
        }
    }
    return res;

}



bool check(int mid)
{
    int u;// 离q近的，距离小
    int l = -1;
    int r = 0;
    for(auto t:zj)
    {
       // cout<<t<<" "<<dis[t]<<endl;
        if(dis[t]<=mid)u=t,l++;
    }
    int v;
    for(int i=zj.size()-1;i>=0;i--)
    {
        int t = zj[i];
       // cout<<t<<" "<<sum-dis[t]<<endl;
        if(sum - dis[t]<=mid){
            v=t;
            r=i;
        }
    }
    //cout<<l<<" "<<r<<endl;



   // cout<<u<<" "<<v<<endl;
    if(dis[v]<dis[u])return true;
    if(dis[v]-dis[u]>s)return false;

    memset(d,-1,sizeof d);
    for(auto t: zj){
        d[t]=0;
    }

    for(int i=l;i<=r;i++)
    {
        if(bfs2(zj[i])>mid)return false;
    }
    return true;
}



void solve()
{
    memset(h,-1,sizeof h);
    //scanf("%d%d",&n,&s);
    cin>>n>>s;
    for(int i=1;i<n;i++)
    {
        int a,b,w;
       cin>>a>>b>>w;
        add(a,b,w);
        add(b,a,w);
    }

    q = bfs(1);
    p = bfs(q);sum=dis[p];
    //cout<<p<<" "<<q<<endl;
    qzj(p,q);
    // for(auto t:zj){
    //     cout<<t<<" ";
    // }cout<<endl;
    //(1);

    int l = 0,r=3032;
    while(l<r)
    {
        int mid = l+r>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;

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