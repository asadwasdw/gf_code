#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{

    int n, m, k;cin >> n >> m >> k;
    vector<array<int, 7>> ask(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 7; j++) cin >> ask[i][j];
    }
    int res = 0;
    vector<int> now(n + 1);
    auto dfs = [&](auto self, int id) -> void {
        if (id == n + 1) {
            int tmp = 0;
            for (auto t : ask) {
                int i = t[0], j = t[1], op = t[2], a = t[3], b = t[4], d = t[5], v = t[6];
                int val = a * now[i] + b * now[j];
                if (op == 0 && val <= d) tmp += v;
                if (op == 1 && val >= d) tmp += v;  
            } 
            res = max(res, tmp);

            return;
        }
        for (int i = 0; i <= k; i++) {
            now[id] = i;
            self(self, id + 1);
        }
    };
    dfs(dfs, 1);


    cout << res << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}