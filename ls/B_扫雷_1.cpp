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
    int n;
    cin >> n;
    vector<PII> f(n+1);
    vector<int> p;
    int res = 0;
    for(int i=1; i<=n; ++i){
        cin >> a[i];
        while(p.size() && a[p.back()] >= a[i])p.pop_back();
        if(p.empty())f[i] = {i / a[i], i % a[i]};
        else f[i] = {f[p.back()].first + (f[p.back()].second + i - p.back()) / a[i], (f[p.back()].second + i - p.back()) % a[i]};
        p.push_back(i);
        res = max(res, f[i].first);
    }
    cout << res << endl;







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