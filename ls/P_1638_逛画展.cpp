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
#define id second

//vector<vector<int>>adj(N);


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    set<int> s;
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
    }

    map<int,int> num;
    int cnt = 0;
    int ans = INF, ansl, ansr;

    for(int r = 1, l = 1; r <= n; r ++) {
        if(num[v[r]] == 0) cnt ++;
        num[v[r]] ++;

        while(num[v[l]] > 1) {
            num[v[l]] --;
            l ++;
        }

        if(cnt == m && ans > r - l + 1) {
            ans = r - l + 1;
            ansl = l;
            ansr = r;
        }
        // cout << l << " " << r << " " << cnt << " " << r - l + 1 << endl;
    }
    // cout << ans;
    cout << ansl << " " << ansr;
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