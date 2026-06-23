#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


ll Inv[N], fac[N];  //分别表示逆元和阶乘
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init(){
    //求阶乘
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    //求逆元
    Inv[N-1]=qmi(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--){
        Inv[i]=Inv[i+1]*(i+1)%mod;
    }
}
 
ll C(int n,int m){
    if(m>n){
        return 0;
    }
    if(m==0)
        return 1;
    return fac[n]*Inv[m]%mod*Inv[n-m]%mod;
}

int dp[110][110];
int g[N][2];


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int x = m/n;int y = m%n;

    for(int i=0;i<=n;i++)
    {
        g[i][0]=qmi(C(n,i),x);
        g[i][1]=qmi(C(n,i),x+1);
       // cout<< g[i][0]<<endl;
    }

    dp[0][0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++){
            for(int h = 0;h<=min(j,n);h++){
               dp[i][j]=(dp[i][j]+dp[i-1][j-h]*g[h][i<=y]%mod)%mod;
            }
        }
    }

    cout<<dp[n][k]<<endl;


}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}