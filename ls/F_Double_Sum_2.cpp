#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


int a[N];
int f1(int x) {
    return x / (x&-x);
}

int f2 (int x) {
    while(x%2 == 0) x /= 2;
    return x;
}

map<__int128_t,__int128_t> s, cnt;
void print(__int128 x)
{
    if (!x) return ;
    if (x < 0) putchar('-'),x = -x;
    print(x / 10);
    putchar(x % 10 + '0');
}
void solve()
{
    int n;
    cin >> n;
    __int128_t ans = 0;
    // for(int i = 1; i <= 100; i ++) cout << f1(i) << " " << f2(i) << endl;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        __int128_t ii = a[i] & -a[i];
        for(int j = 0; j < 64; j ++) {
            __int128_t jj = 1ll << j;
            if(ii == jj) {
                __int128_t t = jj * 2;
                ans += ((__int128_t)s[jj] + cnt[jj] * a[i]) / t;
            } else {
                __int128_t t = min(ii, jj);
                ans += ((__int128_t)s[jj] + cnt[jj] * a[i]) / t;
            }
        }

        s[ii] += a[i];
        cnt[ii] += 1;
        ans += f2(a[i]);
    }

    print(ans);

    // ans = 0;
    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= i; j ++) {
    //         ans += f2(a[i] + a[j]);
    //     }
    //     cout << ans << endl;
    // }






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