#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n;
vector<vector<PII>>edg(N);
int fa[N],dfn[N],tim,cost[N];

int ring[N],ringc,ringd[N];
bool isring[N];
int d[N];
ll ans=0;


void dfs(int u)
{
    dfn[u]= ++tim;

    for(auto t:edg[u]){
        int v = t.first;
        int w = t.second;

        if(v==fa[u])continue;

        if(!dfn[v]){
            fa[v]=u;
            cost[v]=w;
            dfs(v);
        }
        else if(dfn[v]>dfn[u]){

            for(;v!=u;v=fa[v]){
                ringc++;
                isring[v]=true;
                ring[ringc]=v;
                ringd[ringc]=cost[v];
            }
                ringc++;
                isring[u]=true;
                ring[ringc]=u;
                ringd[ringc]=w;
        }
    }
    return;
}

int dfs2(int u,int fa)
{
    int mx1 = 0;
    int mx2 = 0;
   // cout<<u<<endl;
    for(auto t:edg[u]){
        int v=t.first;
        int w= t.second;
        if(isring[v])continue;
        if(v==fa)continue;
        
        int T = dfs2(v,u)+w;
        if(T>=mx1){
            mx2=mx1;
            mx1=T;
        }
        else if(T>mx2){
            mx2=T;
        }
    }
    ans=max(ans,mx1+mx2);
    return mx1;
}
ll A[N],B[N],C[N],D[N];


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edg[u].push_back({v,w});
        edg[v].push_back({u,w});
    }

    dfs(1);
   // for(int i=1;i<=ringc;i++)cout<<ring[i]<<" ";cout<<endl;
   // for(int i=1;i<=ringc;i++)cout<<ringd[i]<<" ";cout<<endl;

    for(int i=1;i<=ringc;i++){
        d[i]=dfs2(ring[i],0);
       // cout<<d[i]<<" "<<ring[i]<<endl;
    }

    ll sum = 0,maxx=0;//maxx维护最大的d[i]-sum[i]

 //cout<<"s\n";

    for(int i=1;i<=ringc;i++){
        sum+=ringd[i-1];//来的时候的权值,注意是i-1,下面是i
        A[i]=max(A[i-1],sum+d[i]);
        B[i]=max(B[i-1],maxx+sum+d[i]);
        maxx=max(maxx,d[i]-sum);
       // cout<<A[i]<<" "<<B[i]<<" "<<sum<<endl;
    }

 //cout<<"s\n";
    sum = 0,maxx=0;
    int tmp = ringd[ringc];
    ringd[ringc]=0;
    
   // for(int i=1;i<=ringc;i++)cout<<ring[i]<<" ";cout<<endl;
    //for(int i=1;i<=ringc;i++)cout<<ringd[i]<<" ";cout<<endl;

    for(int i=ringc;i;i--){
        sum+=ringd[i];
        C[i]=max(C[i+1],d[i]+sum);
        D[i]=max(D[i+1],maxx+sum+d[i]);
        maxx=max(maxx,d[i]-sum);
    }

    //ringd[i]存的是ring[i]到ring[i+1]的距离

    ll ans2 = B[ringc];

    for(int i=1;i<ringc;i++){
        ans2=min(ans2,max({B[i],D[i+1],A[i]+C[i+1]+tmp}));
    }
    cout<<max(ans,ans2)/2.0<<endl;



}


signed main()
{
    cout << setprecision(1) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}