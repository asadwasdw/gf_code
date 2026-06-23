#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n, m, k;cin >> n >> m >> k;
    string s;cin >> s;
    int U = 1, D = n, L = 1, R = m;
    int u = 1, d = n, l = 1, r = m;
    for (auto c : s) {
        if (c == 'U') u++, d++; 
        else if (c == 'D') d--, u--;
        else if (c == 'L') l++, r++;
        else r--, l--;
        U = max(U, u);
        D = min(D, d);
        L = max(L, l);
        R = min(R, r);
    }

    if (U > D || L > R ) {
        if (k == 0) cout << n * m << '\n';
        else cout << 0 << '\n';
        return;
    }
    int del = (D - U + 1) * (R - L + 1) - k;
    if (del < 0) {
        cout << 0 << '\n';
        return;
    }

    vector<vector<int>> f (2 * n + 10, vector<int> (2 * m + 10));
    int basex = n + 1, basey = m + 1;
    int X = basex, Y = basey;
    f[X][Y] = 1;
    for (auto c : s) {
        if (c == 'U') X++;
        else if (c == 'D') X--; 
        else if (c == 'L') Y++;
        else Y--;
        f[X][Y] = 1;
        // cout << X << ' ' << Y << '\n'
    }
    for (int i = 1; i < 2 * n + 10; i++)
    for (int j = 1; j < 2 * m + 10; j++)
        f[i][j] += f[i][j - 1];
    for (int i = 1; i < 2 * n + 10; i++)
    for (int j = 1; j < 2 * m + 10; j++)
        f[i][j] += f[i - 1][j];
    int res = 0;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
        int x = basex - i, y = basey - j;
        int t = f[D + x][R + y] - f[U - 1 + x][R + y] - f[D + x][L - 1 + y] + f[U - 1 + x][L - 1 + y];
        if (t == del) res++;
    }
    cout << res << '\n';
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}