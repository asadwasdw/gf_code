#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

struct warrior{
    int id, l, r;
}w[N * 2];
int n2;
int go[N][25];
int ans[N];
void init() {
    int nxt = 1;
    for(int i = 1; i <= n2; i ++) {
        while(nxt <= n2 && w[nxt].l <= w[i].r) {
            nxt ++;
        }
        go[i][0] = nxt - 1;
    }
    for(int i = 1; i <= 20; i ++) {
        for(int s = 1; s <= n2; s ++) {
            go[s][i] = go[go[s][i - 1]][i - 1];
        }
    } 
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        w[i].id = i;
        cin >> w[i].l >> w[i].r;
        if(w[i].r < w[i].l) w[i].r += m;
    }

    sort(w + 1, w + n + 1,[&](warrior a, warrior b) {
        return a.l < b.l;
    });


    for(int i = 1; i <= n; i ++) {
        w[n + i] = w[i];
        w[n + i].l += m;
        w[n + i].r += m;
    }
    n2 = n * 2;

    init();

    for(int i = 1; i <= n; i ++) {
        int R = w[i].l + m, cur = i, cnt = 1;
        for(int i = 20; i >= 0; i --) {
            int pos = go[cur][i];
            if(pos && w[pos].r < R) {
                cnt += 1 << i;
                cur = pos;
            }
        }
        ans[w[i].id] = cnt + 1;
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << " ";
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
    return 0;
}