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

int a[N];
void solve()
{
    map<int,int> m;
    int n, k; cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        m[a[i]] ++;
    }
    priority_queue<PII,vector<PII>,greater<PII>> q;
    for(auto [x, y] : m) {
        q.push({y, x});
    }

    while(q.size() && k) {
        auto [y, x] = q.top(); q.pop();
        int t = min(y, k);
        y -= t, k -= t;
        if(y) {
            q.push({y, x});
        }
    }
    cout << max(1,(int)q.size()) << endl;



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