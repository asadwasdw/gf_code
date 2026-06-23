#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
vector<vector<int>>edg(N);
int n,m;
char a[N][N];
int bi[N][N],res[30];
PII id[30];
int cnt;
int vis[N][N];
int vis2[30];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int num = 0;

void dfs1(int id,int x,int y)
{
    vis[x][y]=1;
    for(int k=0;k<4;k++){

        int tx = x + dx[k];
        int ty = y + dy[k];

        if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty]||a[tx][ty]=='#'){
            continue;
        }

        if(bi[tx][ty]!=-1)
        {
            //cout<<id<<" "<<bi[tx][ty]<<endl;
            edg[id].push_back(bi[tx][ty]);
            continue;
        }

        dfs1(id,tx,ty);
    }
}

int f[1<<21][21];

int ans = 0;
void dfs2(int s,int x)
{

    if(f[s][x]!=-1){
        return;
    }
    f[s][x]=1;

    if(x==0)
    {
        int res1 = 0;
        memset(vis2,0,sizeof vis2);

        for(int i=1;i<cnt;i++)
        {
            if((s>>i)&1){
                if(!res[i])res1++;

                auto t = id[i];
                int wx = t.first;
                int wy = t.second;

                for(int k=0;k<4;k++)
                {
                    int tx = wx +dx[k];
                    int ty = wy +dy[k];

                    if(tx<1||tx>n||ty<1||ty>m||a[tx][ty]!='@')continue;

                    int si = bi[tx][ty];

                    if((((s>>si)&1)==0)&&vis2[si]==0){
                        res1++;
                        vis2[si]=1;
                    }

                }
            }
        }
        ans=max(ans,res1);
    }

    for(auto y:edg[x])
    {
        if(((s>>y)&1)&&res[y]){
            continue;
        }
        dfs2(s|(1<<y),y);
    }
}



void solve()
{
    while(cin>>n>>m)
    {
        num=0;
    int sx,sy;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            char t;cin>>t;
            a[i][j]=t;

            if((i==1||j==1||i==n||j==m)&&t=='.')
            {
                sx=i;
                sy=j;
            }
        }
    }
    cnt = 0;
    id[cnt]={sx,sy};
    bi[sx][sy]=cnt;
    

    for(int i=2;i<=n-1;i++)
    {
        for(int j=2;j<=m-1;j++)
        {
            if(a[i][j] != '.' && a[i][j]!='#')
            {
                
                bi[i][j]=++cnt;
                id[cnt]={i,j};
                res[cnt]=(a[i][j]=='X');
                //cout<<cnt<<" "<<i<<" "<<j<< " "<<res[cnt]<<endl;
            }
        }
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(bi[i][j]>=0)
            {
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)vis[i][j]=0;

                dfs1(bi[i][j],i,j);
            }
        }
    }
    cnt++;

    ans = 0;
    dfs2(1,0);
    cout<<ans<<"\n";


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            bi[i][j]=-1;
            vis[i][j]=0;
        }
    }

    for(int i=0;i<(1<<cnt);i++){
        for(int j=0;j<cnt;j++){
            f[i][j]=-1;
        }
    }
    for(int i=0;i<cnt;i++)res[i]=0;
  }
}


signed main()
{
    memset(bi,-1,sizeof bi);
    memset(f,-1,sizeof f);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
 
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}