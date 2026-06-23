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


void solve()
{
    vector<ll> ans;
    map<ll,int> st;
    ll n, m; cin >> n >> m;
    ll d = n, sum = 0;
    for(int i = n; i >= 2; i --) {
        if(sum + i + d - 1 > m) continue;
        st[i] = true;
        ans.push_back(i);
        d --;
        sum += i;
        if(i + sum == 0) break;
    }
    ans.push_back(1);
    sum += 1;

    for(int i = 2; i <= n; i ++) {
        if(st[i]) continue;
        ans.push_back(i);
        sum += 1;
    }

    // for(auto t : ans) cout << t << " "; cout << endl;

    if(sum != m) {
        cout << "-1\n";
    } else {
        cout << ans[0] << endl;
        for(int i = 0; i < ans.size() - 1; i ++) cout << ans[i] << " " << ans[i + 1] << endl;
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