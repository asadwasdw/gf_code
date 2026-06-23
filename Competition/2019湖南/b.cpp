#include<bits/stdc++.h>
#define int long long
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


int ans[N];
array<int,3> query[N];
void solve()
{
    int cnt = 0;
    int n, k; 
    while(cin >> n >> k) {
        cnt ++;
        k = min(k, n - k);
        query[cnt] = {n, k, cnt};
    }

    sort(query + 1, query + cnt + 1, [&](array<int,3> a, array<int,3> b){
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });

    n = 1, k = 1;
    __int128_t res = 1;
    const __int128_t e = 1e18;

    auto calc = [&](int _n, int _k) -> ll{
        while(k < _k && res <= e) {
            res = res * (n - k) / (k + 1);
            k++;
        }

        return min(e,res);
    };

    for(int i = 1; i <= cnt; i ++) {
        if(query[i][0] != n) {
            n = query[i][0], k = 0;
            res = 1;
        }

        ans[query[i][2]] = calc(query[i][0],query[i][1]);
    }

    for(int i = 1; i <= cnt; i ++) cout << ans[i] << endl;


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