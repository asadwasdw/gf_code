#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=111+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int st[N][N];
int qp[N][N];
PII match[N][N];
int n,m,k;

int find(int x,int y)
{
    for(int k=0;k<8;k++)
    {
        int X=x+dx[k];
        int Y=y+dy[k];

        if(X<1||X>n||Y<1||Y>m)continue;
        if(qp[X][Y])continue;
        if(st[X][Y])continue;
        st[X][Y]=true;
        if(match[X][Y].first==0||find(match[X][Y].first,match[X][Y].second))
        {
            match[X][Y]={x,y};
            return true;
        }
    }
    return false;

}

void solve()
{

    cin>>n>>m>>k;

    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        qp[a][b]=true;
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(qp[i][j])continue;
            if((i+j)%2)continue;
            memset(st,0,sizeof st);
            if(find(i,j))ans++;
        }
    }

    cout<<n*m-k-ans<<endl;







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