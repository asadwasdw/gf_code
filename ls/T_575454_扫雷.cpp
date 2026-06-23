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

int a[N];
int b[N];
int ans = 0;
int n, d;

int calc(int l, int r) {
    int res = 0;
    for(int i = max(1, l); i <= min(r, n); i++) {
        res += b[i];
    }
    return res;
}

void dfs(int x) {
    if(x == n + 1) {
        bool ky = true;

        for(int i = 1; i <= n; i ++) {
            if(calc(i - 1, i + 1) != a[i]) ky = false;
        }
        if(ky) ans ++;

        // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
        return;
    }


    auto pd = [&]() -> bool{
        bool ky = true;
        if(x > 1) {
            if(calc(x - 2, x) == a[x - 1]) {

            } else ky = false;
        }

        if(calc(x - 1, x + 1) <= a[x]) {

        } else {
            ky = false;
        }

        if(x < n) {
            if(calc(x, x + 2) <= a[x + 1]) {

            } else ky = false;
        }
        return ky;
    };

    if(pd()) dfs(x + 1);
    b[x] = 1;
    if(pd()) dfs(x + 1);
    b[x] = 0;



}

void solve()
{
    
    cin >> n >> d;
    ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    if(d == 1) {
        dfs(1);
        cout << ans << endl;

    } else if(d == 2) {
        cout << "1" << endl;
    } else {
        cout << "4" << endl;
    }






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
} 