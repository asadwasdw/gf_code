#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50; 
const int M = N << 1;
const int mod = 1e9 + 7;
const int inf=0x3f3f3f3f;
struct Info {
    int ans, val, cnt;
    Info() : ans(inf), cnt(0), val(-1) {}
    Info(int x) : ans(inf), cnt(1), val(x) {}
    Info(int ans, int val, int cnt) : ans(ans), val(val), cnt(cnt) {}
}tr[N * 32];

Info operator+ (const Info &a, const Info &b) {
    Info res = Info();
    res.cnt = a.cnt + b.cnt;
    res.ans = min(a.ans, b.ans);
    if(res.cnt == 1) res.val = a.cnt ? a.val : b.val;
    if(a.cnt == 1 && b.cnt == 1) res.ans = a.val ^ b.val;
    return res;
}

int son[N * 32][2];
int idx = 1;

void insert(int u, int x, int dep) {
    if(dep == -1) {
        tr[u].cnt++;
        if(tr[u].cnt == 1) tr[u] = Info(x);
        if(tr[u].cnt >= 2) tr[u].ans = 0;
        return;
    }
    int bit = x >> dep & 1;
    if(!son[u][bit]) son[u][bit] = ++idx;
    insert(son[u][bit], x, dep - 1);
    tr[u] = tr[son[u][0]] + tr[son[u][1]];
}
void del(int u, int x, int dep) {
    if(dep == -1) {
        tr[u].cnt--;
        if(tr[u].cnt == 0) tr[u] = Info();
        if(tr[u].cnt == 1) tr[u] = Info(inf, x, 1);
        return;
    }
    int bit = x >> dep & 1;
    del(son[u][bit], x, dep - 1);
    tr[u] = tr[son[u][0]] + tr[son[u][1]];
}
signed main() {



    int n;
    cin >> n;
    while(n--) 
    {
        int op;
        cin>>op;
        if(op == 1) {
            int x;
            cin >> x;
            insert(1, x, 29);
        } else if(op == 2) {
            int x;
            cin >> x;
            del(1, x, 29);
        } else {
            cout<<tr[1].ans<<'\n';
        }
    }

    return 0;
}
