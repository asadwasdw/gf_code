#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int f[N];
ll n,p;
ll qmi(ll a,ll b)
{
    ll res=1;
    while(b){
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}


struct edg{
    int l,r;
    ll w;
}e[N];

int a[N];

bool cmp(edg a,edg b)
{
    return a.w>b.w;
}

int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return x;
}
void solve()
{
    int cnt=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i],f[i]=i;

   // cout<<qmi(2,2);

    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        cnt++;
        e[cnt]={i,j,(qmi(a[i],a[j])+qmi(a[j],a[i]))%p};
    }

    sort(e+1,e+cnt+1,cmp);

    ll ans=0;

    for(int i=1;i<=cnt;i++)
    {
        int l=e[i].l;
        int r=e[i].r;
        int w=e[i].w;

        if(find(l)==find(r))continue;

       // cout<<l<<" "<<r<<endl;

        f[find(l)]=find(r);
        ans+=w;

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