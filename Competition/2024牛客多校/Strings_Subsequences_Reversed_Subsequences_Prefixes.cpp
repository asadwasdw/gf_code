#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

struct {
    int n;
    vector<ull> h,p,fh;
    const int P = 13331;
    void init(string s, int n) {
        h.resize(n + 10);
        fh.resize(n + 10);
        p.resize(n + 10);
        p[0] = 1;
        s = " " + s;
        for(int i = 1; i <= n; i ++) {
            h[i] = h[i - 1] * P + s[i] - 'a' + 1;
            p[i] = p[i - 1] * P;
        }

        for(int i = n; i >= 1; i --) {
            fh[i] = fh[i + 1] * P + s[i] - 'a' + 1;
        }
    };


    ull get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    ull fget(int l, int r) {
        return fh[l] - fh[r + 1] * p[r - l + 1];
    }
}hxs, hxt;
int cnt[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    string s, t; cin >> s >> t;

    hxs.init(s, n);
    hxt.init(t, m);

    for(int i = n; i >= 1; i --) {
        int r = i;
        int l = i - m + 1;
        cnt[i] = cnt[i + 1];
        if(l < 1) continue;
        // cout << i << " " << hxs.fget(l, r) << " " <<  hxt.get(1, m) << endl;
        if(hxs.fget(l, r) == hxt.get(1, m)) cnt[i] ++;
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << cnt[i] << " \n"[i == n];
    // }


    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int l = i, r = i + m - 1;
        if(r > n) continue;
        if(hxs.get(l, r) == hxt.get(1, m)) {
            cout << i << " " << cnt[r] << endl;
            ans += cnt[r];
        }
    }
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
}