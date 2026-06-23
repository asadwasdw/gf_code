#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

typedef unsigned long long ull;

const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();

typedef pair<ull,ull>hx2;

ull shift(ull x) {
  x ^= mask;
  x ^= x << 13;
  x ^= x >> 7;
  x ^= x << 17;
  x ^= mask;
  return x;
}
int d[N];
ull hx[N];
vector<vector<int>>edg(N);
set<ull> stees;

ull getHash(int u, int fa) {
    hx[u] = 1;
    for(auto  v : edg[u]) {
        if(v == fa) continue;
        if(d[v] >= 2) continue;
        hx[u] += shift(getHash(v, u));
    }
    return hx[u];
}



hx2 get(int n) {
    queue<int>q; 
    for(int i = 1; i <= n; i ++) {
        if(d[i] == 1) q.push(i);
    }

    while(q.size()) { // 找环
        int u = q.front(); q.pop();
        for(auto v : edg[u]) {
            d[v] -- ;
            if(d[v] == 1) q.push(v);
        }
    }
    // 有根树哈希
    vector<ull> hx(n + 10);
    int root = -1;
    for(int i = 1; i <= n; i ++) {
        if(d[i] >= 2) {
            hx[i] = getHash(i, -1);
            // cout << i << " " << hx[i] << endl;
            root = i;
        }
    }
    

    vector<ull>hx3;
    auto dfs = [&](auto dfs,int u,int fa,int root) -> int {
        
        if(u == root && fa != -1) return 0;
        hx3.push_back(hx[u]);
        for(auto v : edg[u]) {
            if(v == fa)continue;
            if(d[v] < 2) continue;
            dfs(dfs, v, u, root);
            break;
        }
        return 0;
    };
    dfs(dfs,root,-1, root);

    auto minimalRepresentation = [&](vector<ull> str) {
        int n = str.size();
        int i = 0,j = 1, k = 0;
        while(i<n && j<n && k<n)
        {
            if(str[(i + k) % n] == str[(j + k)%n])
                k++;
            else
            {
                if(str[(i+k)%n] > str[(j+k)%n])
                    i+=k+1;
                else 
                    j+=k+1;
                if(i==j)
                    j++;
                k = 0;
            }
        }
        return i < j ? i : j;
    };
    
    // for(auto t : hx3) cout << t << " "; cout << endl;
    vector<ull>hx4;
    root = minimalRepresentation(hx3);
    // cout << root << endl;

    for(int i = root; i < hx3.size(); i ++) hx4.push_back(hx3[i]);
    for(int i = 0; i < root; i ++) hx4.push_back(hx3[i]);
    hx2 res = {0, 0};
    const ull P = 13331;


    for(int i = 0 ; i < hx4.size(); i ++) res.first = res.first * P + hx4[i];
    reverse(hx3.begin(),hx3.end());
    hx4.clear();
    root = minimalRepresentation(hx3);
    for(int i = root; i < hx3.size(); i ++) hx4.push_back(hx3[i]);
    for(int i = 0; i < root; i ++) hx4.push_back(hx3[i]);

    for(int i = 0 ; i < hx4.size(); i ++) res.second = res.second * P + hx4[i];
    if(res.first > res.second)  swap(res.first, res.second);
    

    for(int i = 1; i <= n; i ++) {
        edg[i].clear();
        d[i] = 0;
    }
    return res;
}

map<hx2,int>st;

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int m = 0;
        cin >> m;
        for(int j = 1; j <= m; j ++) {
            int u, v;
            cin >> u >> v;
            edg[u].push_back(v);
            edg[v].push_back(u);
            d[u] ++;
            d[v] ++;
        }
        hx2 t = get(m);
        // cout << t.first << " " << t.second << endl;
        st[t] ++;
    }

    cout << st.size() << endl;
    st.clear();

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