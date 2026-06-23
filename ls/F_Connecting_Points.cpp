#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n;
int f[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int u, int v) {
    // cout << u << " - " << v << endl;
    u = find(u), v = find(v);
    if(u == v) return;
    f[u] = v;
}

PII no[N];

void solve()
{

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++) f[i] = i;


    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;

    auto calc = [&](int a, int b) -> ll {
        return 0ll + abs(no[a].first - no[b].first) + abs(no[a].second - no[b].second);
    };



    for(ll i = 1; i <= n; i ++) {
        cin >> no[i].first >> no[i].second;
        for(ll j = 1; j < i; j ++) {
            ll t = calc(i, j);
            // cout << t << " " << j << " " << i << endl;
            pq.push({t, (ll)j, (ll)i});
        }
    }



    while(q --) {
        int op, a, b, u, v;
        cin >> op;
        if(op == 1) {
            cin >> a >> b;
            n ++;
            f[n] = n;
            no[n] = {a, b};
            for(int i = 1; i < n; i ++) {
                ll t = calc(i, n);
                pq.push({t, (ll)i, (ll)n});
            }
        } 
        else if(op == 2) {
            ll k = -1;
            vector<PII> p;

            while(pq.size()) {
                auto T = pq.top(); 
                u = T[1], v = T[2];
                // for(auto t : T) cerr << t << "/ "; cerr << endl;
                // cerr << (k == -1) << " " << k << " " << find(u) << " " << find(v) << endl;
                
                if(k == -1 || k == T[0]) {
                    if(find(u) != find(v)) {
                        k = T[0];
                        p.push_back({u, v});
                    }
                } else break;
                
                pq.pop();
            }
            cout << k << endl;
            
            for(auto [u, v] : p) {
                merge(u, v);
            }
            
        } 
        else {
            cin >> u >> v;
            if(find(u) == find(v)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
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