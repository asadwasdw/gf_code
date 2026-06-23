#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<vector<int>>edg2(N);


int dfn[N],low[N],dfnc;
int n,m,sta[N],top;
stack<int>stk;
int nn;


void ad2(int x,int y)
{
    edg2[x].push_back(y);
}
 
void tarjan(int now,int fa){
    dfn[now]=low[now]=++dfnc;
    sta[++top]=now;
    for(auto u:edg[now]){
        if(!dfn[u]){
            tarjan(u,now);
            low[now]=min(low[now],low[u]);
            if(dfn[now]<=low[u]){
                nn++;
                ad2(nn,now),ad2(now,nn);
                cout<<nn<<" "<<now<<endl;
                while(1){
                    int xx=sta[top--];
                    ad2(xx,nn),ad2(nn,xx);
                    cout<<nn<<" "<<xx<<endl;
                    if(xx==u) break;
                }
            }
        } else if(u!=fa){
            low[now]=min(low[now],dfn[u]);
        }
    }
}
int f[N][22],dep[N];
bool vis[N];
void dfs(int now,int fa){

    vis[now]=1;
    dep[now]=dep[fa]+1;
    f[now][0]=fa;

    for(int i=1;(1<<i)<=dep[now];i++){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(auto u:edg2[now]){
        if(u!=fa && !vis[u]){
            dfs(u,now);
        }
    }
}
int LCA(int xx,int yy){
    if(dep[xx]>dep[yy]) swap(xx,yy);
    int len=dep[yy]-dep[xx],k=0;
    while(len){
        if(len&1){
            yy=f[yy][k];
        }
        k++,len>>=1;
    }
    if(xx==yy) return xx;
    for(int i=20;i>=0;i--){
        if(f[xx][i]==f[yy][i]) continue;
        xx=f[xx][i],yy=f[yy][i];
    }
    return f[xx][0];
}
int solve(int xx,int yy){
    return (dep[xx]+dep[yy]-2*dep[LCA(xx,yy)])/2-1; 
}

struct E
{
    int l,r;
}e[N];


void solve()
{
    
    nn=n;

    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
        e[i]={a,b};
    }

    for(int i=1;i<=n;i++)
    {
        reverse(edg[i].begin(),edg[i].end());
    }

    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])tarjan(i,-1);
    }

    for(int i=1;i<=nn;i++)
    {
        reverse(edg2[i].begin(),edg2[i].end());
    }


    // for(int i=1;i<=nn;i++)
    // {
    //     cout<<i<<endl;
    //     for(int t:edg2[i])cout<<t<<" ";
    //     cout<<endl;
    //     cout<<endl;
    // }

    for(int i=1;i<=nn;i++)
    {
        if(!vis[i])dfs(i,0);
    }
    int q;cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        //cout<<e[a].l<<" "<<e[a].r<<" "<<e[b].r<<" "<<e[b].l<<endl;
        int ans1  = solve(e[a].l,e[b].l);
        int ans2  = solve(e[a].l,e[b].r);
        int ans3  = solve(e[a].r,e[b].l);
        int ans4  = solve(e[a].r,e[b].r);

        int ans = max({ans1,ans2,ans3,ans4});
       cout<<ans<<endl;
    }

}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;

    while(1)
    {
        cin>>n>>m;
        if(n==m&&n==0)break;
        solve();
    }
}