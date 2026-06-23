#include<bits/stdc++.h>
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
int b[N];



bool check(int mid) {
    multiset<int> s[2];
    for(int i = 1; i <= n; i ++) {
        // cout << i << " " << a[i] << " " << b[i] << endl;
        int st = b[i];
        if(s[st ^ 1].size()) {
            auto t = s[st ^ 1].lower_bound(mid - a[i]);
            if(t != s[st ^ 1].end()) s[st ^ 1].erase(t);
            else return false;
        }
        else s[st].insert(a[i]);
    }
    return true;
}


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    // cout << check(6) << endl;

    int l = 0, r = 4e8+1;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;






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