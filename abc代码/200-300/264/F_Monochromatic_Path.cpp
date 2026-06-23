#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2100+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

ll dp[N][N][2][2];

int a[N][N];
int R[N],C[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>R[i];
    }
    for(int i=1;i<=m;i++){
        cin>>C[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t;
            cin>>t;
            a[i][j]=t-'0';
        }
    }


    memset(dp,0x3f,sizeof dp);
    dp[1][1][0][0]=0;
    dp[1][1][1][0]=R[1];
    dp[1][1][0][1]=C[1];
    dp[1][1][1][1]=R[1]+C[1];


    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int kr=0;kr<2;kr++)
                for(int kc=0;kc<2;kc++){

                    if(i!=n){
                        if((a[i+1][j]^kc)==(a[i][j]^kr^kc)){
                            dp[i+1][j][0][kc]=min(dp[i+1][j][0][kc],dp[i][j][kr][kc]);
                        }
                        else dp[i+1][j][1][kc]=min(dp[i+1][j][1][kc],dp[i][j][kr][kc]+R[i+1]);
                    }

                    if(j!=m){
                        if((a[i][j+1]^kr)==(a[i][j]^kr^kc)){
                            dp[i][j+1][kr][0]=min(dp[i][j+1][kr][0],dp[i][j][kr][kc]);
                        }
                        else dp[i][j+1][kr][1]=min(dp[i][j+1][kr][1],dp[i][j][kr][kc]+C[j+1]);
                    }
                }

    
    cout<<min({dp[n][m][1][1],dp[n][m][0][0],dp[n][m][1][0],dp[n][m][0][1]})<<endl;
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