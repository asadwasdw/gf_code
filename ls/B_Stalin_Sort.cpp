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
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i ++) {
        int x; cin >> x;
        a.push_back(x);       
    }
  
    int ans = INF;
    for(int i = 0; i < n; i ++) {
        int res = 0;
        for(int j = 0; j < n; j ++) {
            if(j < i || a[j] > a[i]) res ++;
        }
        ans = min(res, ans);
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