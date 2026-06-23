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


int a[N], b[N], c[N];

void solve()
{
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i ++) {
        a[i] = i; 
        b[i] = i; // 绳子
        c[i] = i; 
    }

    while(q --) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            a[x] = c[y];
        } else if(op == 2) {
            cin >> x >> y;
            swap(b[c[x]], b[c[y]]);
            swap(c[x], c[y]);
        } else {
            cin >> x;
            cout << b[a[x]] << endl;
        }

        // for(int i = 1; i <= n; i ++) {
        //     cout << a[i] << " " << b[i] << " " << c[i] << endl;
        // } 
    }
}

void solve2() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        a[i] = i;
    }

    while(q --) {
        int op, x, y;
        cin >> op;
        if(op == 1) {
            cin >> x >> y;
            a[x] = y;
        } else if(op == 2) {
            cin >> x >> y;
            for(int i = 1; i <= n; i ++) {
                if(a[i] == x) a[i] = y;
                else if(a[i] == y) a[i] = x;
            }
        } else {
            cin >> x;
            cout << a[x] << endl;
        }
    }
}

int op[N], x[N], y[N];

void solve3() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        a[i] = i;
        b[i] = i;
    }
    bool ky = true;
    for(int i = 1; i <= q; i ++) {
        cin >> op[i];
        if(op[i] <= 2) cin >> x[i] >> y[i];
        else cin >> x[i];
        if(op[i] == 1) ky = false;
    }

    if(!ky) {
        for(int i = 1; i <= q; i ++) {
            if(op[i] == 1) {
                a[x[i]] = y[i];
            } else if(op[i] == 2) {
                for(int j = 1; j <= n; j ++) {
                    if(a[j] == x[i]) a[j] = y[i];
                    else if(a[j] == y[i]) a[j] = x[i];
                }
            } else {
                cout << a[x[i]] << endl;
            }
        }
    } else {
        for(int i = 1; i <= q; i ++) {
            if(op[i] == 1) {

            } else if(op[i] == 2) {
                int tx = b[x[i]], ty = b[y[i]];
                swap(a[tx], a[ty]);
                swap(b[x[i]], b[y[i]]);
            } else {
                cout << a[x[i]] << endl;
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
    // cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}