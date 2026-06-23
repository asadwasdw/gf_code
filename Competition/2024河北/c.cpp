#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

struct qj {
    int l, r, id;
}a[N];

bool cmp(qj a, qj b) {
    if(a.l == b.l)return a.r < b.r;
    return a.l < b.l;
} 
// vector<pair<int, int>> g[N]

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    vector<int> ans;
    multiset<pair<int, int>> p;
    int u = 1;
    for(int i=0; i<=2e6; ++i){
        while(p.size() && p.begin()->first < i)p.erase(p.begin());
        while(u <= n && a[u].l == i)p.insert({a[u].r, a[u].id}), ++u;
        if(p.size()){
            // cout << p.begin()->second << endl;
            ans.push_back(p.begin()->second);
            p.erase(p.begin());
            
        }
        else break;
    }

    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); ++i)cout << ans[i] << " \n"[i == ans.size()-1];







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