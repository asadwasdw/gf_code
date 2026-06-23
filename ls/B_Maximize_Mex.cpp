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
    int n, x;
    cin >> n >> x;
    unordered_map<int,queue<PII>> adj;
    vector<int> a(n, 0);
    map<int,int> num;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    bool ky = true;
    sort(a.begin(),a.end());

    for(int i = 0; i < n; i ++) {
        adj[a[i]%x].push({a[i]%x, a[i]});
    }

    int ans = 0;

    while(adj[ans%x].size() && adj[ans%x].front().second <= ans) {
        adj[ans%x].pop();
        ans ++;
    }
    cout << ans << endl;







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