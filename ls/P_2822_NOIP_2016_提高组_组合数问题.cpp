#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=10007 - 5;
const int mod=10007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

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
    return fac[n]%mod*Inv[m]%mod*Inv[n-m]%mod;
}


const int M = 2e3 + 10;
int c[M][M];
int s[M][M];

void solve()
{
    int t, k;
    cin >> t >> k;
    for(int i = 0; i <= 2e3; i ++) {
        c[i][0] = 1;
        for(int j = 1; j <= i; j ++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            // cout << c[i][j] << " \n"[j == i]; 
        }
    }

    for(int i = 1; i <= 2e3; i ++) {
        for(int j = 1; j <= i; j ++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (c[i][j] == 0);
            // cout << s[i][j] << " \n"[j == i]; 
        }
        s[i][i + 1] = s[i][i]; //前缀和需要用
    }

    while(t --) {
        int n, m;
        cin >> n >> m;
        cout << s[n][min(n, m)] << endl;
    }

}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}