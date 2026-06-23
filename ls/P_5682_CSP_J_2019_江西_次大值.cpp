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

int a[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> ans;
    if(v.size() != n) ans.push_back(0);

    for(int i = 0; i < v.size() - 1; i ++) {
        ans.push_back(v[i]);
        ans.push_back(v[v.size() - 1] % v[i]);
    }


    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    if(ans.size() >= 2) cout << ans[ans.size() - 2] << endl;
    else cout << "-1" << endl;






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