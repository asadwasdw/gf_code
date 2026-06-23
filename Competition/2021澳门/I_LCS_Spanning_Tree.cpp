#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

struct SuffixArray {
    int n;
    vector<int> sa, rk, lcp;
    SuffixArray(const string &s) {
        n = s.length();
        sa.resize(n);
        lcp.resize(n - 1);
        rk.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int a, int b) {return s[a] < s[b];});
        rk[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
        int k = 1;
        vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while (rk[sa[n - 1]] < n - 1) {
            tmp.clear();
            for (int i = 0; i < k; ++i)
                tmp.push_back(n - k + i);
            for (auto i : sa)
                if (i >= k)
                    tmp.push_back(i - k);
            fill(cnt.begin(), cnt.end(), 0);
            for (int i = 0; i < n; ++i)
                ++cnt[rk[i]];
            for (int i = 1; i < n; ++i)
                cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; --i)
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            swap(rk, tmp);
            rk[sa[0]] = 0;
            for (int i = 1; i < n; ++i)
                rk[sa[i]] = rk[sa[i - 1]] + (tmp[sa[i - 1]] < tmp[sa[i]] || sa[i - 1] + k == n || tmp[sa[i - 1] + k] < tmp[sa[i] + k]);
            k *= 2;
        }
        for (int i = 0, j = 0; i < n; ++i) {
            if (rk[i] == 0) {
                j = 0;
            } else {
                for (j -= j > 0; i + j < n && sa[rk[i] - 1] + j < n && s[i + j] == s[sa[rk[i] - 1] + j]; )
                    ++j;
                lcp[rk[i] - 1] = j;
            }
        }
    }
};

void solve()
{
    int n; cin >> n;
    string s;
    int m = 0;
    vector<int> pre{0};
    for (int i = 0; i < n; i++) {
        string t; cin >> t;
        t += '#';
        m += t.size();
        s += t;
        pre.push_back(m);
    }
    SuffixArray sa(s);
    // for (int i = 0; i < m; i++) cout << sa.sa[i] << ' ' << sa.rk[i] << '\n';
    // cout << s << '\n';
    vector<array<int, 3>> edge;
    for (int i = 1; i < m; i++) {
        int idx = upper_bound(pre.begin(), pre.end(), sa.sa[i]) - pre.begin();
        int idy = upper_bound(pre.begin(), pre.end(), sa.sa[i - 1]) - pre.begin();
        if (idx == idy) continue;
        if (sa.sa[i] + 1 == pre[idx] || sa.sa[i - 1] + 1 == pre[idy]) continue;
        int val = min({sa.lcp[i - 1], pre[idx] - sa.sa[i] - 1, pre[idy] - sa.sa[i - 1] - 1});
        // cerr << sa.lcp[i - 1] << ' ' << pre[idx] << ' ' << sa.sa[i] << ' ' << pre[idy] << ' ' << sa.sa[i - 1] << '\n';
        edge.push_back({val, idx, idy});
    }
    sort(edge.rbegin(), edge.rend());
    vector<int> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    ll sum = 0;
    auto find = [&](auto self, int x) -> int {
        return x == fa[x] ? x : fa[x] = self(self, fa[x]);
    };
    auto merge = [&](int x, int y) -> bool {
        x = find(find, x), y = find(find, y);
        if (x == y) return false;
        fa[x] = y;
        return true;
    };
    for (auto [w, u, v] : edge) {
        // cerr << w << ' ' << u << ' ' << v << '\n';
        if (merge(u, v)) sum += w;
    }
    cout << sum << '\n';


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