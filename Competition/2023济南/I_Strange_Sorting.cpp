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


void solve()
{
    int l = 0, r = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    map<int,int>mp;
    vector<PII> ans;
    for(int i = 1; i <= n; i ++) {
        if(i == a[i]) continue;
        int r = n;
        while(r > i && a[r] > a[i]) r--;
        ans.push_back({i, r});
        sort(a + i, a + r + 1);
    }
    cout << ans.size() << endl;
    for(auto [a, b] : ans) cout << a << " " << b << endl;

    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
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