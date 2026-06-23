#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

int a[N], b[N], d[N];
int n;
bool check1() {
    vector<int> rd(n + 1);
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i = 1; i <= n; i ++) {
        rd[i] = d[i];
        if(rd[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int u = q.top(); q.pop();
        ans.push_back(u);

        for(auto v : adj[u]) {
            -- rd[v];
            if(rd[v] == 0) q.push(v);
        }
    }
    // for(auto t : ans) cout << t << " "; cout << endl;
    if(ans.size() != n) return false;

    for(int i = 0; i < n; i ++) {
        if(a[i] != ans[i]) return false;
    }
    return true;
}

bool check2() {
    vector<int> rd(n + 1);
    vector<int> ans;
    priority_queue<int> q;
    for(int i = 1; i <= n; i ++) {
        rd[i] = d[i];
        if(rd[i] == 0) {
            q.push(i);
        }
    }

    while(q.size()) {
        int u = q.top(); q.pop();
        ans.push_back(u);

        for(auto v : adj[u]) {
            -- rd[v];
            if(rd[v] == 0) q.push(v);
        }
    }
    // for(auto t : ans) cout << t << " "; cout << endl;
    if(ans.size() != n) return false;

    for(int i = 0; i < n; i ++) {
        if(b[i] != ans[i]) return false;
    }
    return true;
}

void solve()
{
    
    cin >> n;
    {
        stack<int> s;
        for(int i = 0; i < n; i ++) {
            int x; cin >> x; a[i] = x;
            while(s.size() && s.top() < x) s.pop();
            if(s.size()) {
                adj[s.top()].push_back(x);
                // cout << s.top() << " " << x << endl;
            }
            s.push(x);
        }
    }

    {
        stack<int> s;
        for(int i = 0; i < n; i ++) {
            int x; cin >> x; b[i] = x;
            while(s.size() && s.top() > x) s.pop();
            if(s.size()) {
                adj[s.top()].push_back(x);
                // cout << s.top() << " " << x << endl;
            }
            s.push(x);
        }
    }
    vector<PII> ans;
    for(int i = 1; i <= n; i ++) {
        for(auto v : adj[i]) ans.push_back({i, v}), ++d[v];
    }

    if(check1() && check2()) {
        cout << "Yes\n";

        cout << ans.size() << endl;
        for(auto [u, v] : ans) cout << u << " " << v << endl;
    } else {
        cout << "No\n";
    }




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