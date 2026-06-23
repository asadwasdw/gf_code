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
vector<int> v;

int calc(int l1, int r1, int l2, int r2) {
    int l = *lower_bound(v.begin(), v.end(), l1);
}


void solve()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;        
    cout << calc(l1, r2, l2, r2);
    
}


signed main()
{
    
    v.push_back(0);
    for(int i = 0; (1 << i) <= 2e6; i ++) {
        v.push_back(1 << i);
    }
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