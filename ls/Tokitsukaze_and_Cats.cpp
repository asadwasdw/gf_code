#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=300+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int c[N][N];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int ans = 0;
    for(int i=1;i<=k;i++) {
        int a,b;
        cin>>a>>b;
        c[a][b]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(c[i][j])
            for(int k=0;k<4;k++)  {
                int x = i + dx[k];
                int y = j + dy[k];
                if(c[x][y])ans++;
            }
        }
    }

    cout<<k*4-ans/2<<"\n";



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