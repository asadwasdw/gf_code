#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

ull a[N], b[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    stack<ull> s;
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i ++) {
        while(s.size() && a[s.top()] <= a[i]) {
            int t = s.top();s.pop();
            b[t] = 0;
            if(t <= i - k) ans2 --;
        }
        s.push(i);
        b[i] = 1;
        if(i - k >= 1 && b[i - k] == 1) ans2 ++;
        
        // cout << i << " " << s.size() << " " << ans2 << endl;

        if(i >= k) cout << s.size() - ans2 << endl;
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