#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m;
int deep[N];
int fa[N][25];

void dfs(int x,int father)
{
    deep[x]=deep[father]+1;
    fa[x][0]=father;
    for(int i=1;(1ll<<i)<=deep[x]&&i<=19;i++)
        fa[x][i]=fa[fa[x][i-1]][i-1];
    
    for(auto v:edg[x]){
        if(v==father)continue;
        dfs(v,x);
    }
}

int lca(int x,int y)
{
    if(deep[x]<deep[y])swap(x,y);
    for(int i=19;i>=0;i--){
        if(deep[fa[x][i]]>=deep[y]){
            x=fa[x][i];
        }
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--)
    {
        if(fa[x][i]==fa[y][i])continue;
        x=fa[x][i];
        y=fa[y][i];
    }
    return fa[x][0];
}

int len(int a,int b,int d)
{
    if(d==0)d=lca(a,b);
    return deep[a]+deep[b]-2*deep[d];
}


void solve()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    dfs(1,0);
    //cout<<lca(5,6)<<endl;
    //cout<<len(5,4)<<endl;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);

        int d1=lca(a,b);
        int d3=lca(c,b);
        int d2=lca(a,c);

        int t1 = len(a,b,d1)+len(d1,c,0);
        int t2 = len(a,c,d2)+len(d2,b,0);
        int t3 = len(b,c,d3)+len(d3,a,0);

        int ans = min({t1,t2,t3});
        int d;

        if(t1==ans){
            d=d1;
        }
        else if(t2== ans)d=d2;
        else d=d3;
        printf("%d %d\n",d,ans);
    }  

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}