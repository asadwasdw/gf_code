#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"
constexpr int N = 1e6+10, mod = 1e9+7;

int k3[N];
int n,m;

int len[N * 2], fail[N * 2];
map<int, int> tr[N * 2];
int idx, last;
void sam_init(){
    idx = 0;
    len[0] = 0;
    fail[0] = -1;
    idx++;
    last = 0;
}

void sam_extend(int c){
    int cur = idx++;
    len[cur] = len[last] + 1;
    int p = last;
    while(p != -1 && !tr[p].count(c)){
        tr[p][c] = cur;
        p = fail[p];
    }
    if(p == -1){
        fail[cur] = 0;
    }
    else{
        int q = tr[p][c];
        if(len[p] + 1 == len[q]){
            fail[cur] = q;
        }
        else{
            int clone = idx++;
            len[clone] = len[p] + 1;
            tr[clone] = tr[q];
            fail[clone] = fail[q];
            while(p != -1 && tr[p].count(c) && tr[p][c] == q){
                tr[p][c] = clone;
                p = fail[p];
            }
            fail[q] = fail[cur] = clone;
        }
    }
    last = cur;
}

int check(int c){
    int p = last;
    while(p != -1 && !tr[p].count(c)){
        p = fail[p];
    }
    if(p == -1){
        return len[last] + 1;
    }
    else{
        int q = tr[p][c];
        if(len[p] + 1 == len[q]){
            return len[last] + 1 - len[q];
        }
        else{
            return len[last] + 1 - len[p] - 1;
        }
    }
    return 0;
}


void solve() {
    while(cin >> n >> m){
        sam_init();
        ll res = 0;
        for(int i=1,x; i<=n; ++i){
            cin >> x;
            sam_extend(x);
            // res += len[last] -len[fail[last]];
        }
        for(int i=1; i<=m; ++i){
            res ^= (ll)k3[i] * check(i) % mod;
        }
        cout << res << endl;
        for(int i=0; i<=idx; ++i){
            len[i] = fail[i] = 0;
            tr[i].clear();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    k3[0] = 1;
    for(int i=1; i<N; ++i)k3[i] = (ll)k3[i-1] * 3 % mod;
    // cin >> t;
    while (t--) {
        solve();
    }
}