#include<bits/stdc++.h>
#define int long long
#define cyx using
#define is namespace
#define handsame std
cyx is handsame;

int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar();
    return k;
}

int n,m,a[120][80],vis[120][80];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int tx[100005],ty[100005];
bool ok=0;

void dfs(int x,int y,int step)
{
    if(ok) return; 
    tx[step]=x; ty[step]=y;
    if(x==n && y==m)
    {
        for(int i=1;i<=step;i++) cout<<tx[i]<<" "<<ty[i]<<endl;
        ok=1;
        return;
    }

    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<1||ny<1||nx>n||ny>m) continue;
        if(a[nx][ny]==1 || vis[nx][ny]) continue;

        vis[nx][ny]=1;
        dfs(nx,ny,step+1);
        // vis[nx][ny]=0;

        if(ok) return; 
    }
}

signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s; cin>>s;
        for(int j=1;j<=m;j++)
        {
            if(s[j-1]=='*') a[i][j]=1;
            else a[i][j]=0;
        }
    }
    vis[1][1]=1;
    dfs(1,1,1);
    return 0;
}