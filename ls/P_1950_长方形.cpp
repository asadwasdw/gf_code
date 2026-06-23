#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

char c[N][N];
int h[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> c[i][j];
            if(c[i][j] == '.') h[i][j] = h[i - 1][j] + 1;

            // cout << h[i][j] << " \n"[j == m];
        }
    }

    ll ans = 0;

    auto calc = [&](int x) -> void {
        vector<int> l(m + 2, 0), r (m + 2, 0);
        stack<int> s;
        for(int i = 1; i <= m; i ++) {
            while(s.size() && h[x][s.top()] >= h[x][i]) {
                s.pop();
            }
            if(s.size()) l[i] = s.top();
            s.push(i);

            // cout << l[i] << " \n"[i == m];
        }

        while(s.size()) s.pop();

        for(int i = m; i >= 1; i --) {
            while(s.size() && h[x][s.top()] > h[x][i]) {
                s.pop();
            }
            if(s.size()) r[i] = s.top();
            else r[i] = m + 1;

            s.push(i);
        }

        // for(int i = 1; i <= m; i ++) {
        //     cout << r[i] << " \n"[i == m];
        // }

        for(ll i = 1; i <= m; i ++) {
            ans += (i - l[i]) * (r[i] - i) * h[x][i];
        }

    };

    // calc(1);

    
    for(int i = 1; i <= n; i ++) {
        calc(i);
    }
    
    cout << ans << endl;










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