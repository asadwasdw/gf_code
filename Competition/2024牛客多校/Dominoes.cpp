#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n,m;
int a[N];

vector<int> lsh;


int get(int x) {
    return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin();
}
PII e[N];
#define x first
#define y second

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int u, v;
        cin >> u >> v;
        e[i] = {u, v};
        lsh.push_back(u);
        lsh.push_back(v);
    }
    lsh.push_back(0);
    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
    int m = lsh.size() - 1;
    bool ky = true;
    vector<int> ans2;

    for(int i = 1; i <= n; i ++) {
        e[i].x = get(e[i].x);
        e[i].y = get(e[i].y);
        if(e[i].x > e[i].y) swap(e[i].x, e[i].y);

        if(e[i].x == e[i].y) {
            ans2.push_back(e[i].x);
        }
        else {
            cout << e[i].x << endl;
            edg[e[i].x].push_back(e[i].y);

        }
    }
    vector<PII> ans1;

    for(int i = 1; i <= m; i ++) {
        for(auto j : edg[i]) {
            ans1.push_back({j, i});
        }
    }
    for(auto [i, j] : ans1) cout << i << " " << j << endl;
    sort(ans2.begin(), ans2.end());

    int l = 0, r = ans2.size() - 1;

    while(l < r) {
        if(ans2[l])
    } 







    cout << "S" << endl;

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