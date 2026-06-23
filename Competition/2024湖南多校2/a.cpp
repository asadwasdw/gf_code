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
const int M = 3;
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

    void print(){
        for(int i = 1; i < M;i ++) {
            for(int j = 1; j < M; j ++) {
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
                        c.m[i][j] = (c.m[i][j] + mod)% mod;
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

ll qmi(ll a,ll b ){
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return qmi(x,mod-2) % mod;
}

void solve()
{
    int x1,y1,n;
    cin >> x1 >> y1 >> n;
    ll k = x1*inv(y1)%mod;
    ll sx = 2*k*inv(k*k%mod+1)%mod;
    ll cx = ((k*k%mod-1+mod) %mod) * inv(k*k%mod+1)%mod;
    // cout << k << ' '<< sx << ' ' << cx << '\n';
    matrix a1(0),A(0);
    a1.m[1][1] = -1;
    a1.m[2][1] = 0;

    A.m[1][1] =  cx;
    A.m[1][2] =  -sx;
    A.m[2][1] =  sx;
    A.m[2][2] =  cx;
    // a1.print();
    // A.print();

    matrix ans = a1*qmi(A,n+1);
    // ans.print();
    cout << ans.m[1][1]%mod << endl;
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