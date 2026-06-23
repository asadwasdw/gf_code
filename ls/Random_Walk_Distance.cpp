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

long double ans = 0;

void dfs(int n, int x, int y, long double p) {
    if(n == 0) {
        ans += p * abs(x - y);
        return;
    }

    dfs(n - 1, x + 1, y, p / 2);
    dfs(n - 1, x - 1, y, p / 2);

}

void print(double p) {
    for(int i = 1; i <= 10000; i ++) {
        for(int j = 512; j <= 512; j ++) {
            if(1.0 * i / j == p) {
                int t = 512/j;
                cout << setw(3) << i * t << '/';
                cout << setw(3) << j * t << " ";
                return;
            }
        }
    }
    cout << " -1/ -1 ";
}




void solve()
{
    // int n, y;
    // cin >> n >> y;

    // dfs(n, 0, y, 1);
    // cout << ans << endl;

    for(int i = 1; i <= 20; i ++) {
        for(int j = 1; j <= 10; j ++) {
            ans = 0;
            dfs(i, 0, j, 1);
            print(ans);
        }
        cout << endl;
    }




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(8) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}