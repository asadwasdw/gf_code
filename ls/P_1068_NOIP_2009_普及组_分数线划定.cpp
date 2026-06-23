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


void solve()
{
    int n, m;
    cin >> n >> m;
    // priority_queue<PII, vector<PII>, greater<PII> > q;
    vector<PII> v;

    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    sort(v.begin(), v.end(), [&](PII a, PII b){
        if(a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });

    m = min(n, (int)(m * 1.5));

    int g = v[m - 1].second;

    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(v[i].second >= g) cnt ++;
    }

    cout << g << " " << cnt << endl;
    for(int i = 0; i < cnt; i ++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

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