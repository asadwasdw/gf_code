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

//vector<vector<int>>adj(N);
typedef long double db; 
const db pi =acos(-1);

db len(int x1, int y1, int x2, int y2) {
    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    return sqrtl(x * x + y * y);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<db> t;
    for(int i = 1; i <= n; i ++) {
        int x, y, r;
        cin >> x >> y >> r;
        db L = r - len(x, y, 0, 0);
        if(L <= 0) t.push_back(0);
        else {
            db area  = pi * r * r * L;
            t.push_back(area);
        }
    }
    sort(t.begin(), t.end());

    db ans = 0;
    for(int i = 0; i < n - k; i ++) {
        ans += t[i];
    }
    cout << ans;



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