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

struct seg{
    int l, r, id;
}s[N];


void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        int l, r; cin >> l >> r;
        s[i] = {l, r, i};
    }

    vector<int> ans;
    ll sum = 0;

    sort(s + 1, s + n + 1, [&](seg a, seg b){
        return a.l < b.l;
    });

    int r = 0;
    for(int i = 1; i <= n; i ++) {
        if(s[i].r > r) {
            r = s[i].r;
            ans.push_back(s[i].id);
        }
    }
    cout << ans.size() << endl;
    for(auto t : ans) cout << t << " "; cout << endl;
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