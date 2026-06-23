#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int b[N][20];
int a[N];
int lg2[N];

int query(int l, int r) {
    int lg = lg2[r - l + 1];
    // cout << l << " " << r << " " << lg << " "<<  b[r - (1 << lg) + 1][lg]<< " " << endl;
    return __gcd(b[l][lg], b[r - (1 << lg) + 1][lg]);

}
void solve()
{
    int n;
    cin >> n;
    
    for(int i = 2; i <= n; i ++) {
        lg2[i] = lg2[i >> 1] + 1;
    }

    int cnt1 = 0;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i][0] = a[i];
        cnt1 += a[i] == 1;
    }

    if(cnt1) {
        cout << n - cnt1 << endl;
        return;
    }

    for(int j = 1; j < 20; j ++ ) {
        for(int i = 1; i <= n; i ++) {
            b[i][j] = gcd(b[i][j - 1], b[min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }


    int ans = INF;
    for(int l = 1, r = 1; r <= n; r ++) {
        while(l < r && query(l + 1, r) == 1) l ++;
        if(query(l, r) == 1) {
            ans = min(ans, r - l);
        }
    }
    ans += n - 1;
    if(ans >= INF) ans = -1;
    cout << ans << endl;











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
    return 0;
}