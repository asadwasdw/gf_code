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
int a[N];

// while (((!sta.empty() && sta.top().id == l && sta.top().w + 1 == x) || x == 1) && l > 0) {
// 	if (!sta.empty()) sta.pop();
// 	--l;
// } 



bool check(int mid) {
    stack<PII> s;
    for(int i = 2; i <= n; i ++) {
        if(a[i] > a[i - 1]) continue;
        while(s.size() && s.top().first > a[i]) s.pop();
        int len = a[i];
        while(((s.size() && s.top().first == len && s.top().second + 1 == mid) || mid == 1) && len > 0) {
            if(s.size())s.pop();
            len--;
        }  

        if(len == 0) return false;
        int v = 0;
        if(s.size() && s.top().first == len) v = s.top().second;
        ++ v;
        if(s.size() && s.top().first == len) s.pop();
        s.push({len, v});
    }
    return true;

}


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    // cout << check(2) << endl;

    int l = 1, r = 1e9 + 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l;
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