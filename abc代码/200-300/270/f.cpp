#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

struct edg{
    int l,r,w;
}E[N],e[N];

bool cmp(edg a,edg b)
{
    return a.w<b.w;
}
int x[N];
int y[N];

int f[N],sz[N];

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return f[x];
}


int js(int n,int m)
{
    //cout<<n<<" "<<m<<endl;
    for(int i=0;i<=n+10;i++)f[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)e[i]=E[i];
    sort(e+1,e+m+1,cmp);


    ll res=0;

    for(int i=1;i<=m;i++)
    {
        int l = e[i].l;
        int r = e[i].r;

        int fl=find(l);
        int fr=find(r);

        if(fl==fr)continue;
        sz[fr]+=sz[fl];
        f[fl]=fr;
        res+=e[i].w;
    }
    if(sz[find(n)]!=n){
        return INFll;
    }
    else return res;
}


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>x[i];
    }

    for(int i=1;i<=n;i++){
        cin>>y[i];
    }

    int ans = INFll;

    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        E[i]={a,b,w};
    }

    ans  = min(ans,js(n,m));

    for(int i=1;i<=n;i++)
    {
        E[i+m].l=i;
        E[i+m].r=n+1;
        E[i+m].w=y[i];
    }
    ans = min(ans,js(n+1,m+n));
    //cout<<js(n+1,m+n)<<endl;
    for(int i=1;i<=n;i++)
    {
        E[i+m].l=i;
        E[i+m].r=n+1;
        E[i+m].w=x[i];
    }
    ans = min(ans,js(n+1,m+n));
    //cout<<js(n+1,m+n)<<endl;


    for(int i=1;i<=n;i++)
    {
        E[i+m].l=i;
        E[i+m].r=n+1;
        E[i+m].w=x[i];
    }

    for(int i=1;i<=n;i++)
    {
        E[i+m+n].l=i;
        E[i+m+n].r=n+2;
        E[i+m+n].w=y[i];
    }

     ans = min(ans,js(n+2,m+n+n));

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