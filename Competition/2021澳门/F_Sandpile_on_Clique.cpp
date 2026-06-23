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

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    int n; cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    if (sum > n * (n - 2)) {
        cout << "Recurrent\n";
        return;
    }
    sum = 0;
    priority_queue<array<ll, 2>> que;
    for (int i = 0; i < n; i++) {
        que.push({a[i], i});
    }
    int cnt2 = 0;
    while (1) {
        cnt2 ++ ;
        if(cnt2 > 5e5) break;
        auto [val, idx] = que.top(); que.pop();
        if (val + sum < n - 1) break;
        ll cnt = (val + sum) / (n - 1);
        sum += cnt;
        a[idx] -= cnt * n;
        que.push({a[idx], idx});
    }
    if(cnt2 > 5e5) {
        cout << "Recurrent\n";
        return;
    }
    for (int i = 0; i < n; i++) cout << a[i] + sum << " \n"[i == n-1];
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