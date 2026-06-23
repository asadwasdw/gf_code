#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=510;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int dp[2][N][2*N];
int a[N][N];

void solve()
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            cin>>a[i][j];   
        }
    }


    if(q>n+m-1||p>n+m-1){
        cout<<"0"<<endl;
        return ;
    }

    dp[1][1][a[1][1]]++;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=1000;k++){
                //cout<<(i%2)<<" "<<j<<" "<<k<<endl;

                // if(dp[i%2][j][k]==0)continue;

                // int yx = n-i + m -j;
                // int x1 = k;
                // int x2 = n+m-1-x1;

                // if(x1+yx<q)continue;
                // if(x2+yx<p)continue;


                if(i!=n){
                    dp[(i+1)%2][j][k+a[i+1][j]]+=dp[i%2][j][k];
                    dp[(i+1)%2][j][k+a[i+1][j]]%=mod;
                }

                if(j!=m){
                    dp[i%2][j+1][k+a[i][j+1]]+=dp[i%2][j][k];
                    dp[i%2][j+1][k+a[i][j+1]]%=mod;
                }
                //cout<<i<<" "<<j<<" "<<k<<endl;
                 //cout<<dp[i][j][k]<<endl;
                 if(i!=n)dp[i%2][j][k]=0;
            }
        }

    }


    ll ans = 0;
    for(int k=0;k<=1000;k++){
        int x1= k;
        int x2= n+m-1-k;
        if(x1>=q&&x2>=p){
            ans+=dp[n%2][m][k];
            ans%=mod;
        }
    }

    cout<<ans%mod<<endl;



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