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

int n, k;
struct seg{
    int l, r;
}s[N];
int R = INF;
int lr[N];
bool check(ll mid) {
    int cnt = 0;
    int r = -INF;
    for(int i = 1; i <= n; i ++) {
        if(s[i].l > r + mid || (mid && s[i].l == r + mid)) {
            cnt ++;
            r = lr[i];
        }
    }
    // cout << mid << " " << cnt << endl;
    return cnt >= k;
}

void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i].l >> s[i].r;
        R = min(R, s[i].r);
    }

    sort(s + 1, s + n + 1,[&](seg a, seg b){
        if(a.l != b.l) return a.l < b.l;
        return a.r < b.r;
    });
    lr[n + 1] = INF;
    for(int i = n; i >= 1; i --) {
        lr[i] = min(s[i].r, lr[i + 1]);
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << s[i].l << " " << lr[i] << endl;
    // }

    // cout << check(2) << endl;
    // cout << check(3) << endl;



    ll l = 0, r = INF;
    while(l < r) {
        ll mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }

    if(l)cout << l << endl;
    else if(check(l)) cout << 0 << endl;
    else cout << "-1";





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