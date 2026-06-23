#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int g[N][N];
int match[N],n,m;
bool vis[N],succ[N];
int hide[N];


bool dfs(int x)
{
    for(int i=1;i<=n;i++)
        if(g[x][i]&&!vis[i]){
            vis[i]=true;
            if(match[i]==0||dfs(match[i])){
                match[i]=x;
                return true;
            }
        }
    return false;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
    }

    for(int i=1;i<=n;i++)g[i][i]=1;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++){
                g[i][j]|=g[i][k]&g[k][j];
            }
        }
    }
    for(int i=1;i<=n;i++)g[i][i]=0;


    int ans = n;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        ans-=dfs(i);
    }
  

    for(int i=1;i<=n;i++)
    {
       //if(match[i])cout<<i<<" "<<match[i]<<endl;
        succ[match[i]]=true;
    }

      cout<<ans<<endl;
    // for(int i =1 ,k=0;i<=n;i++){
    //     if(!succ[i])hide[++k]=i,cout<<i<<" ";
    // }cout<<endl;
    // memset(vis,0,sizeof vis);
    // bool modify = true;
    // while(modify)
    // {
    //     modify=false;

    //     for(int i=1;i<=ans;i++)
    //         for(int j=1;j<=n;j++)
    //             if(g[hide[i]][j])vis[j]=true;
    //     for(int i=1;i<=ans;i++)
    //         if(vis[hide[i]]){
    //             modify = true;
    //             while(vis[hide[i]])hide[i]=match[hide[i]];
    //         }
    // }

    // for(int i=1;i<=ans;i++)cout<<hide[i]<<" ";cout<<endl;


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