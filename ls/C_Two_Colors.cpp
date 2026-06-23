#include<bits/stdc++.h>
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

int tr[N];

void add(int k, int x) {
    if(k <= 0) return;
    for(int i = k; i < N; i += i & -i) tr[i] += x;
}

int sum(int k) {
    if(k <= 0) return 0;
    int res = 0;
    for(int i = k; i; i -= i & -i ) res += tr[i];
    return res;
}

int get(int l, int r) {
    return sum(r) - sum(l - 1);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i ++) cin >> a[i];


    for(int i = 1; i <= k; i ++) {
        add(min(n - 1,a[i]), 1);
    }

    // 

    ll ans = 0;
    ll ans2 = 0;
    for(int i = n - 1; i >= 1; i --) {
        ll t = get(i, i);
        if(t) {
            add(i, -1);
            // cout << i << " " << t << " " << get(n - i, n) << endl;
            ans += t * get(n - i, n);

            if(n % 2 == 0 && i == n / 2) {
                ans2 += t * get(i, i);
            }

            add(i, - (t - 1));
            add(i - 1, t);

        }
    }
    cout << ans * 2 - ans2 << endl;




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}