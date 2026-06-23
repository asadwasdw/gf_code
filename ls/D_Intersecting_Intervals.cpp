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

//vector<vector<int>>edg(N);
int n,m;
PII a[N];


void solve()
{
    priority_queue<int> q;
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) {
        auto [x,y] = a[i];
        while(q.size() && -q.top() < x) q.pop();
        ans += q.size();
        q.push(-y);
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