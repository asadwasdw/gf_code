#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

#define int long long
ll tr[N][2]; // 0 行， 1列

void add(int k, int x, int id) {
    for(int i = k; i < N; i += i & - i) {
        tr[i][id] += x;
    }
}

int get(int k, int id) {
    int res = 0;
    for(int i = k; i; i -= i & -i) {
        res += tr[i][id];
    }
    return res;
}

int get(int l, int r, int id) {
    return get(r, id) - get(l - 1, id);
}

int lastr[N], lastc[N];

void solve()
{
    int n, q;
    cin >> n >> q;

    ll ans = 0;

    for(int i = 1; i <= q; i ++) {
        int op, x;
        cin >> op >> x;
        if(op == 1) {
            if(lastr[x] == 0) {
                ans += n;
            } else {
                ans += get(lastr[x], i, 0);
                add(lastr[x],-1, 1);
            }
            lastr[x] = i;
            add(lastr[x], 1, 1);
        } else {
            if(lastc[x] == 0) {
                ans -= get(i, 1);
            } else {
                ans -= get(lastc[x], i, 1);
                add(lastc[x],-1, 0);
            }
            lastc[x] = i;
            add(lastc[x], 1, 0);
        }
        cout << ans << endl;
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