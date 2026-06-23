#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


int a[N];

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>>adj(n + 10);

    for(int i = 1; i <= 2 * n; i ++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }

    auto check = [&](int x, int y) -> int {
        if(x == 0 || y == 0 || x == y) return 0;
        if(abs(adj[y][0] - adj[y][1]) == 1) return 0;
        if(abs(adj[x][0] - adj[x][1]) == 1) return 0;
        vector<int> v;
        v.push_back(adj[x][0]);
        v.push_back(adj[x][1]);
        v.push_back(adj[y][0]);
        v.push_back(adj[y][1]);
        sort(v.begin(), v.end());
        if(v[1] - v[0] == 1 && v[3] - v[2] == 1 )  return 1;
        return 0;
    };

    map<PII,int> st;

    long long ans = 0;

    for(int i = 1; i <= 2 * n; i ++) {
        if(check(a[i], a[i + 1])) {
            // cout << a[i] << " " << a[i + 1] << endl;
            int u = a[i], v = a[i + 1];
            if(u > v) swap(u, v);
            st[{u, v}] = true;
        }
    }
    cout << st.size()  << endl;

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