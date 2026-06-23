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
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if(l1 > l2) {
        swap(l1, l2);
        swap(r1, r2);
    }
    int ans;
    if(l2 > r1) {
        ans = 1;
    } else if(r2 <= r1) {
        ans = r2 - l2;
        if(l1 != l2) ans ++;
        if(r1 != r2) ans ++;  
    } else {
        ans = r1 - l2;
        if(l1 != l2) ans ++;
        if(r1 != r2) ans ++;  
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