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
void tarjan(int now,int fa){//重点，构建一个圆方树，原来的点是圆点，同一个点双连接同一个方点
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


    {
        memset(f,0,sizeof(f));
        dfnc=0;
        for(int i=1;i<=nn;i++){
            edg[i].clear();
            edg2[i].clear();
            low[i]=0;
            dfn[i]=0;
            e[i]={0,0};
            dep[i]=0;
            vis[i]=0;
        }

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

/*
发现现有题解好像都没讲为什么是选答案更大的那个，提供一篇也许严谨的有证明的题解。

题目求的是两条边之间的必经点，从边考虑比较不容易，我们先从点的角度开始思考。

观察“必经点”的特殊性，可以发现若是两个点间有两条及以上的简单路径，且其中有两条路径没有公共点，就说明这两个点没有必经点（这里指的必经点不包括起点和终点），而从刚才分析出的性质入手，我们可以尝试对整张图的点双缩点。

缩点后，可以发现若是两个点在同一个点双中，没有必经点，否则就是他们在缩点后树上简单路径经过的割点，我们可以建一棵圆方树，由于方点和圆点交替出现，利用深度就可以计算出答案。

由点到边，对于每条边按点思考，分出以下几种情况：

若是两个点在同一个点双内，任选一个圆点代替这条边即可。

若一个点是割点，另一个点不是，则不是的那个节点一定是圆方树的叶子节点，如果另外一条边不在方点中，可以把这条边当做深度较深的那个节点看待，在方点中此方法也成立。

若两个点都是割点，若另外一边不在两点间的方点上，则选取选取后能增加答案的那个点（必经），若在方点上，可以随便取，用上述方法也可解决。

综上，我们总是选取能使答案变更大的节点进行计算，所以我们可以直接不用分类讨论，在组合的四组情况中选取答案最大的那个答案即可。
*/