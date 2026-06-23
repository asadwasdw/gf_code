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
    vector<PII> v;
    int n; cin >> n;
    for(int i = 0; i < n; i ++) {
        int x, y; cin >> x >> y;
        // if(x > y) swap(x,y);
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(),[&](PII a, PII b){
        if(min(a.first, a.second) != min(b.first, b.second)) {
            return min(a.first, a.second) < min(b.first, b.second);
        } 

        return max(a.first, a.second) < max(b.first, b.second);
    });

    for(int i = 0; i < n ; i ++) {
        cout << v[i].first << " " << v[i].second << " ";

    }

    cout << endl;







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