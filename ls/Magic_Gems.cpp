#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
const int M = 105;
struct matrix{
    int m[M][M]={0};
    matrix(){};
    matrix(int t){
        for(int i = 1; i < M;i ++) {
            for(int j = 1; j < M; j ++) {
                m[i][j] = t;
            }
        }
    }

    void print(int n){
        for(int i = 1; i <= n;i ++) {
            for(int j = 1; j <= n; j ++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

matrix operator * (const matrix& a, const matrix & b) {
    matrix c(0);
    for(int i = 1; i < M;i ++) {
        for(int k = 1; k < M; k ++) 
            if(a.m[i][k]) 
                for(int j = 1; j < M; j ++) 
                    if(b.m[k][j]) {
                        c.m[i][j] += a.m[i][k] * b.m[k][j];
                        c.m[i][j] %= mod;
                    }
    }
    return c;
}

matrix qmi(matrix a, int b) {
    matrix res(0);
    for(int i = 1; i < M; i ++) res.m[i][i] = 1;
    while(b) {
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
 


int dp[N];
void solve()
{
    dp[0] = 1;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= min(n,105ll); i++) {
        dp[i] += dp[i - 1];
        if(i >= m) dp[i] += dp[i - m];
        dp[i]  %= mod;
    }

    matrix res(0),t(0);
    for(int i = 1;i <= m;i ++) {
        res.m[1][i] = dp[i];
        if(i != m){
            t.m[i + 1][i] = 1;
        }
        else {
            t.m[i][i] = t.m[1][i] = 1;
        }
    }
    // t.print(m);

    if(n <= m) cout << dp[n] << endl;
    else {
        cout << (res*(qmi(t,n-m))).m[1][m]<<endl;
    }
    // cout << "x\n";  
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