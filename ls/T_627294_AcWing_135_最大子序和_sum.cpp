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

int a[N], s[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
        // cout << i << " " << s[i] << endl;
    }
    deque<int> dq;
    dq.push_back(0);
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        while(dq.size() && i - dq.front() > m) dq.pop_front();
        while(dq.size() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
        // cout << i << " " << dq.front() << endl;
        ans = max(ans, s[i] - s[dq.front()]);
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
    return 0;
}