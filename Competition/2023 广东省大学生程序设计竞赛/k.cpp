#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int n,m,k;

int a[7][7];


int dx1[]={1,-1,0,0};
int dy1[]={0,0,-1,1};
int dx2[]={2,-2,0,0};
int dy2[]={0,0,-2,2};

int ans;

void dfs(int X,int Y)
{
    
    for(int i=0;i<4;i++)
    {
        int x1=dx1[i]+X;
        int y1=dy1[i]+Y;
        int x2=dx2[i]+X;
        int y2=dy2[i]+Y;

        if(x1<1||x2<1||x1>n||x2>n||y1<1||y2<1||y1>m||y2>m)continue;

        if(a[x1][y1]==0)continue;
        if(a[x2][y2])continue;

        k--;
        ans=min(ans,k);

        a[X][Y]=0;
        a[x1][y1]=0;
        a[x2][y2]=1;

        for(int x=1;x<=n;x++)
        {
            for(int y=1;y<=m;y++)
            {
                if(a[x][y])dfs(x,y);
            }
        }

        a[X][Y]=1;
        a[x1][y1]=1;
        a[x2][y2]=0;


        k++;

    }

}


void solve()
{
    cin>>n>>m>>k;
    ans=k;

    memset(a,0,sizeof a);
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j])dfs(i,j);
        }
    }

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}