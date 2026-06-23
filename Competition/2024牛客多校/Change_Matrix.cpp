#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[50][50];

int euler(int n) {
    int ans = n;
    for(int p = 2;  p * p <= n; ++ p) {
        if(n % p == 0) {
            ans = ans/p*(p - 1);
            while(n % p == 0)
                n /= p;
        }
    }

    if(n != 1) ans = ans/n * (n - 1);
    return ans;
}


void solve()
{

    int n; cin >> n;
    int sum2 = 0;
    for(int i = 1; i <= n; i ++) {
        int sum = 0;
        for(int j = 1; j <= n; j ++) {
            a[i][j] = __gcd(i, j);
        }
    }

    int m; cin >> m;
    for(int i = 1; i <= m; i ++) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        // cout << op << " " << x << " " << y << endl;
        if(op == 'R') {
            for(int i = 1; i <= n; i ++) a[x][i] = a[x][i] * y % mod;
        } else {
            for(int i = 1; i <= n; i ++) a[i][x] = a[i][x] * y % mod;
        }
        int sum = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                sum += a[i][j];
            }
        }
        sum %= mod;
        cout << i << " " << sum << endl;
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) cout << a[i][j] << " \n"[j == n];
    // }
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}