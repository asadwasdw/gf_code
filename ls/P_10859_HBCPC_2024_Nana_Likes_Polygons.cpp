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
    int n;
    cin >> n;
    vector<PII> v;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }


    auto calc = [&](PII a, PII b, PII c) {
        PII ac = {c.first - a.first, c.second - a.second};
        PII ab = {b.first - a.first, b.second - a.second};
        int t = ac.second * ab.first - ac.first * ab.second;
        if(t == 0) return 1.0 * INF;

        double area = fabs(t)/2;
        return area;
    };

    double ans = INF;

    for(int i = 0; i < n; i ++) {
        for(int j = i + 1; j < n;j ++) {
            for(int z = j + 1; z < n; z ++) {
                double area = calc(v[i], v[j], v[z]);
                // cout << i << " " << j << " " << z << " " << area << endl;
            
                ans = min(ans, area);
            }
        }
    }
    
    if(ans > INF - 1) cout << "-1";
    else cout << ans;

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