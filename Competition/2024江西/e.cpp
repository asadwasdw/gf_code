#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);



void solve()
{
    unordered_map<int,vector<PII>> ST;
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    n = min(n, 30);

    int n1 = n/2;
    int n2 = n - n1;
    bool ky = false;
    int ans;
    
    auto dfs = [&](auto self, int id, int sum, int st1, int st2) -> void {
        // cout << id << " " << sum << endl;
        if(ST[0].size()) return;
        if(id == n1 + 1) {
             
            if(st1 == 0 && st2 == 0) return;
            ST[sum].push_back({st1, st2});
            return;
        }
        self(self, id + 1, sum + a[id], st1 | (1 << id), st2);
        self(self, id + 1, sum, st1, st2);
        self(self, id + 1, sum - a[id], st1, st2 | (1 << id));
    };
    dfs(dfs, 1, 0, 0, 0);       
    vector<int> st[N];
    for(int i = 1; i <= n1; i ++) {
        for(int j = 0; j <= 2; j ++) {
            
        }
    }

    auto dfs2 = [&](auto self, int id, int sum, int st1, int st2) -> void {
        if(ST[0].size()) return;
        // if(ky) return;
        if(id == n + 1) {
            if(st1 == 0 && st2 == 0) return;
            if(!ky || sum == 0)ST[sum].push_back({st1, st2});
            if(ST[sum].size() >= 2 && !ky) {
                ky = true;
                ans = sum;
            }
            return;
        }
        self(self, id + 1, sum + a[id], st1 | (1 << id), st2);
        self(self, id + 1, sum, st1, st2);
        self(self, id + 1, sum - a[id], st1, st2 | (1 << id));
    };
    dfs2(dfs2, n1 + 1, 0, 0, 0);

    // cout << n1 << " " << n2 << endl;

    auto print = [&](PII res) {
        cout << __builtin_popcount((unsigned int)(res.first)) << " ";
        for(int i = 1; i <= n; i ++) if((res.first >> i) & 1) cout << i << " ";
        cout << endl;

        cout << __builtin_popcount(res.second) << " ";
        for(int i = 1; i <= n; i ++) if((res.second >> i) & 1) cout << i << " ";
        cout << endl;
    };

    if(ST[0].size()) {
        print(ST[0][0]);
    }
    else if(ky) {
        // cout << ans << endl;

        PII res1 = ST[ans][0], res2 = ST[ans][1];
        PII res = {res1.first | res2.second, res1.second | res2.first};
        print(res);
    }
    else {
        cout << "-1\n";
    }
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