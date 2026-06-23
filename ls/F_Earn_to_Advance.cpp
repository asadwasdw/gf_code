#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct G{
    int w,x,y;
}g[N];

bool cmp(G a, G b){
    return a.w < b.w;
}
int dp[85][85][85][85];

int p[85][85];
int r[85][85];
int d[85][85];
int n;
int dp2[N],dp3[N];

void init(){
    memset(dp,0x3f,sizeof dp);
    memset(dp3,0x3f,sizeof dp2);
    memset(dp2,0x3f,sizeof dp3);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            dp[i][j][i][j] = 0;
            for(int i1 = i;i1<=n;i1++) {
                for(int j1 =j;j1<=n;j1++){
                   if( i== i1 && j==j1)continue;
                   if(i1 != 1) dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][j][i1 - 1][j1] + d[i1-1][j1]);
                   if(j1 != 1) dp[i][j][i1][j1] = min(dp[i][j][i1][j1], dp[i][j][i1 ][j1 - 1] + r[i1][j1 - 1]);
                }
            }
        }
    }
}



void solve()
{
    cin >> n;
    int m = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            cin>>p[i][j];
            g[++m] = {p[i][j],i,j};
        }

    sort(g+1,g+m,cmp);

    for(int i=1;i<=n;i++)
        for(int j=1;j<n;j++) cin>>r[i][j];
        
    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++) cin>>d[i][j];

    init();
    

    for(int i=1;i<=m;i++){
        if(g[i].x==1 && g[i].y == 1) {
            dp2[i] = 0;
            dp3[i] = 0;
        }
    }

    for(int i=1;i<=m;i++) {
        // cout << i <<" --";
        for(int j = 1;j < i;j++) {
            if(g[j].x > g[i].x || g[j].y > g[i].y) continue;
            if(dp2[j] >= INF/2)continue;
            // cout << j <<" ";
            int sum = dp[g[j].x][g[j].y][g[i].x][g[i].y];
            int cnt = max(0ll,(sum - dp3[j] ) + g[j].w - 1) / g[j].w; 
            int dy = dp3[j] + cnt*g[j].w - sum;
            int W = g[i].x - g[j].x  + g[i].y - g[j].y  + dp2[j] + cnt;

            if(dp2[i] > W) {
                dp2[i] = W;
                dp3[i] = dy;
            }
            else if(dp2[i] == W) dp3[i]  = max(dp3[i],dy);
        }
        // cout<<endl;
    }

    cout << dp2[m] << endl;
    


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}