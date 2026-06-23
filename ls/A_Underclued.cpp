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

int n;
int a[100][100];
map<vector<int>,int> st;

void dfs(int x, int y) {
    if(y == n + 1) {
        x ++;
        y = 1;
    }
    if(x == n + 1) {
        vector<int> t;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                a[n + 1][j] += a[i][j];
                a[i][n + 1] += a[i][j];
            }
        }

        for(int i = 1; i < n; i ++) {
            t.push_back(a[i][n + 1]);
            a[i][n + 1] = 0;
        }

        for(int i = 1; i < n; i ++) {
            t.push_back(a[n + 1][i]);
            a[n + 1][i] = 0;
        }

        t.push_back(a[n + 1][n + 1]);
        a[n + 1][n + 1] = 0;

        st[t]++;
        return;
    }

    dfs(x, y + 1);
    a[x][y] = 1;
    dfs(x, y + 1);
    a[x][y] = 0;
}


void solve()
{
    cin >> n;
    dfs(1, 1);

    for(auto [x, y] : st) {
        for(auto t : x) cout << t << " ";
        cout << y << endl;
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
}