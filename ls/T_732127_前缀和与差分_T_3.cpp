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

int row[N], col[N];

void solve()
{
    int n; 
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        vector<int>x, y;
        for(int j = 1; j <= 3; j ++) {
            int tx, ty;
            cin >> tx >> ty;
            tx ++, ty ++;
            x.push_back({tx});
            y.push_back({ty});
        } 

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int lx = x[0] + 1, rx = x[2] - 1, ly = y[0] + 1, ry = y[2] - 1;

        // if(x[0] == x[1])lx --;
        // if(x[2] == x[1])rx ++;
        // if(y[0] == y[1])ly --;
        // if(y[2] == y[1])ry ++;

        row[lx] ++, row[rx + 1] --;
        col[ly] ++, col[ry + 1] --;
    }


    for(int i = 1; i < N; i ++) {
        row[i] += row[i - 1];
        col[i] += col[i - 1];

        // cout << i << " " << row[i] << " " << col[i] << endl;
    }
    int q;cin >> q;
    while(q --) {
        char op; cin >> op;
        if(op == 'x') {
            int x; cin >> x;
            cout << row[x + 1] << endl;
        } else {
            int y; cin >> y;
            cout << col[y + 1] << endl;
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