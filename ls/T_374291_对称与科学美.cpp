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

int a[N];
typedef unsigned long long ull;
void solve()
{
    mt19937_64 rnd(time(0));
    map<ull,ull> cnt;
    map<ull,ull> hx;
    int n;
    cin >> n;
    ull res = 0;
    ll ans = 0;
    cnt[0] = 1;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(hx[a[i]] == 0) {
            hx[a[i]] =rnd();
        }
    }

    for(int i = 1; i <= n; i ++) {
        res ^= hx[a[i]];
        ans += cnt[res];
        cnt[res] ++;
    }
    cout << ans;






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