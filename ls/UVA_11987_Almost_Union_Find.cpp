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

ll f[N], cnt[N], sum[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int p, int q) {
    p = find(p), q = find(q);
    if(p == q) return;
    cnt[q] += cnt[p];
    sum[q] += sum[p];
    f[p] = q;
}

void solve()
{
    int n, m;
    while(cin >> n >> m) {

    for(int i = 1; i <= n; i ++) {
        f[i] = n + i;
        cnt[i] = 1;
        sum[i] = i;
    }

    for(int i = n + 1; i <= 2 * n; i ++) {
        f[i] = i;
        cnt[i] = 1;
        sum[i] = i - n;
    }
    
    while(m --) {
        int op;
        cin >> op;
        int p, q;
        if(op == 1) {
            cin >> p >> q;
            merge(p, q);
        } else if(op == 2) {
            cin >> p >> q;
            if(find(p) == find(q)) continue;
            cnt[find(p)] --;
            cnt[find(q)] ++;

            sum[find(p)] -= p;
            sum[find(q)] += p;

            cnt[p] = 1;
            sum[p] = p;

            f[p] = find(q);
        } else {
            cin >> p;
            p = find(p);
            cout << cnt[p] << " " << sum[p] << endl;
        }

        // for(int i = 1; i <= 2 * n; i ++) cout << find(i) << " \n"[i == 2 * n];
        // for(int i = 1; i <= 2 * n; i ++) cout << cnt[find(i)] << " \n"[i == 2 * n];
        // for(int i = 1; i <= 2 * n; i ++) cout << sum[find(i)] << " \n"[i == 2 * n];
        // cout << endl;
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
    return 0;
}