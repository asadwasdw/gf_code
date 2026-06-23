#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    bool ky = false;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int ans = 0;

    for(int i = 30; i >= 0; i --) { 
        vector<int> b;
        for(int j = 0; j < a.size(); j ++) {
    
            if((a[j] >> i) & 1) {
                b.push_back(a[j]);
            } 
        }

        if(b.size() >= k) {
            ans |= (1 << i);
            a = b;
        }
    }
    cout << ans << endl;
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