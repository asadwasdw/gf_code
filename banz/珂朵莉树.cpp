#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
//https://zhuanlan.zhihu.com/p/106353082
//vector<vector<int>>edg(N);

// 支持区间覆盖操作和求区间第k小
// 其他操作直接暴力
// 玄学

struct node{
    ll l, r;
    mutable ll v;
    node(ll l, ll r, ll v) : l(l), r(r), v(v) {};
    bool operator < (const node &o) const {
        return l < o.l;
    }
};

set<node> tree;

auto split(ll pos){
    auto it = tree.lower_bound(node(pos,0,0));
    if(it != tree.end() && (*it).l == pos) return it;
    it --;
    ll l = (*it).l, r = (*it).r, v = (*it).v;
    tree.erase(it);
    tree.insert(node(l, pos-1, v));
    return tree.insert(node(pos, r, v)).first;
}

void assgin(ll l, ll r, ll v) {
    auto end = split(r + 1), begin = split(l);
    tree.erase(begin,end);
    tree.insert(node(l, r, v));
}

ll qmi(ll a, ll b, ll p) {
    ll ans = 1;
    a %= p;
    while(b) {
        if (b & 1) ans = ans * b % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}

void add(ll l, ll r, ll v) {
    auto end = split(r + 1);
    for (auto it = split(l); it != end; it ++) {
        it->v += v;
    }
}

ll kth(ll l, ll r, ll k) {
    auto end = split(r + 1);
    vector<pair<ll,ll>> v;
    for (auto it = split(l); it != end; it ++) {
        v.push_back({it->v, it->r - it->l + 1});
    }

    sort(v.begin(), v.end());
    for (auto &t : v) {
        k -= t.second;
        if (k <= 0) 
            return t.first;
    }
}


void solve()
{




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