#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

// 无根树哈希

vector<vector<int>>edg(N);
typedef unsigned long long ull;

const ull mask = std::chrono::steady_clock::now().time_since_epoch().count();//随机数

ull shift(ull x){
    x ^= mask;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= mask;
    return x;
}

typedef pair<ull,ull>Hash2;
map<Hash2,int>trees;

int n;
ull h[N];
int siz[N],weight[N],centroid[2];

void getCentroid(int x, int fa) { // 找重心
    siz[x] = 1;
    weight[x] = 0;
    for (int i : edg[x]) {
        if (i == fa) {
           continue;
        }
        getCentroid(i, x);
        siz[x] += siz[i];
        weight[x] = max(weight[x], siz[i]);
    }
    weight[x] = max(weight[x], n - siz[x]);
    if (weight[x] <= n / 2) {
        int index = centroid[0] != 0;
        centroid[index] = x;
    }
}

set<ull> s;
ull getHash(int u,int fa) {
    h[u]=1;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        getHash(v,u);
        h[u] += shift(h[v]);
    }
    s.insert(h[u]);
    return h[u];
}


void solve()
{

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    getHash(1, 0);
    cout << s.size();
    

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