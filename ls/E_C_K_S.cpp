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

int n, k;
int num[3][2];

vector<ll> gets(int flag) {
    vector<int> a(n + 1, 0);
    vector<vector<int>>adj(n + 1);

    for(int i = 1; i <= n; i ++) cin >> a[i],num[flag + 1][a[i]]++;

    int m; cin >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(n + 1, false);
    vector<int> color(n + 1, 0);

    auto dfs = [&] (auto self, int u) -> void {
        if (vis[u]) return;
        vis[u] = true;
        for (int v : adj[u]) {
            color[v] = (color[u] + 1) % k;
            self(self, v);
        }
        return;
    };
    dfs(dfs, 1);
    vector<int> in(k, 0), out(k, 0);
    for(int i = 1; i <= n; i ++) {
        if(a[i]) out[color[i]] ++;
        else in[color[i]]++;
    }

    vector<ll> res;
    for(int i = 0; i < k; i ++) {
        ll u = in[i] * 100010ll + out[i];
        if(flag) {
            u = out[(i - 1 + k)%k] * 100010ll + in[(i + 1) % k];
        }
        res.push_back(u);
    }
    return res;
}

typedef unsigned long long ull;
ull h1[N],h2[N],p[N];
const ull P = 1000000000000711;

ull get1(int l, int r) {
    return h1[r] - h1[l - 1] * p[r - l + 1];
}

ull get2(int l, int r) {
    return h2[r] - h2[l - 1] * p[r - l + 1];
}

vector<ll> z_function (const vector<ll>& s) {
	ll n = (ll) s.size();
	vector<ll> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1ll, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

void solve()
{
    memset(num, 0, sizeof num);
    cin >> n >> k;
    auto s1 = gets(0);
    auto s2 = gets(1);

    if((num[1][1] == n && num[2][0] == n) || (num[1][0] == n && num[2][1] == n)) {
        cout << "YES\n";
        return;
    }

    p[0] = 1;
    for(int i = 0; i < k; i ++) {
        h1[i + 1] = h1[i] * P + s1[i];
        h2[i + 1] = h2[i] * P + s2[i];
        p[i + 1]  = p[i] * P;
    }
    for(int i = k; i < 2 * k; i ++) {
        h2[i + 1] = h2[i] * P + s2[i - k];
        p[i + 1]  = p[i] * P;
    }

    for(int i = 1; i <= k; i ++) {
        int l = 0, r = k;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(get1(1, mid) == get2(i, i + mid - 1))l = mid;
            else r = mid - 1;
        }
        // cout << l << endl;
        if(l >= k) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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