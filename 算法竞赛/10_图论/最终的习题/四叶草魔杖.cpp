#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const int M = 1<<20;
int n,m;
int a[N];
int f[M];

struct edge{
    int l,r,w;
}E[N];

int fa[20];

bool cmp(edge a,edge b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}


int js(int S)
{
    int sum = 0;
    int C= 0;
    bool st[32];
    for(int i=0;i<n;i++){
        if((S>>i)&1){
            C++;
            st[i]=true;
            sum+=a[i];
        }
    }
   // cout<<S<<" "<<sum<<endl;

    if(sum!=0)return INF;

    for(int i=0;i<n;i++){
        fa[i]=i;
    }
    int ans = 0;
    int cnt = 0;

    for(int i=0;i<m;i++){
        
        int l = E[i].l;
        int r = E[i].r;
        //cout<<l<<" "<<r<<" "<<E[i].w<<endl;
        if(!(st[l]&&st[r]))continue;

        int fl =find(l);
        int fr =find(r);
        if(fl==fr)continue;
        ans+=E[i].w;
        cnt++;
        fa[fl]=fr;

        // for(int i=0;i<n;i++){
        //     cout<<find(i)<<" ";
        // }cout<<endl;
    }
   // cout<<S<<"sss\n";
    //cout<<S<<" "<<cnt<<endl;
    if(cnt!=C-1)ans=INF;
    return ans;
}



void solve()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int l,r,w;
        cin>>l>>r>>w;
        E[i]={l,r,w};
    }

    sort(E,E+m,cmp);
    for(int i=1;i<((1<<n));i++){
        f[i]=js(i);
        // if(f[i]!=INF)
        //     cout<<i<<" "<<f[i]<<endl;
    }
    //cout<<"S"<<endl;


    vector<ll>dp(M,INF);
    dp[0]=0;

    for(int S = 1;S<(1<<n);S++)
    {
        for(int S0=S;S0;S0=(S0-1)&S){//所有子集
            dp[S]=min(dp[S],dp[S^S0]+f[S0]);
        }
    }

    int S  = 5;
    for(int S0=S;S0;S0=(S0-1)&S){
        cout<<S0<<endl;
    }


    ll res = dp[(1<<n)-1];
    if(res>=INF)cout<<"Impossible";
    else cout<<res;
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