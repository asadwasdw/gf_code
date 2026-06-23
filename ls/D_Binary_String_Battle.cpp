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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        char t; cin >> t;
        a[i] = t - '0';
        if(a[i]) num ++;
    }

    if(num <= k || k * 2 > n) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }







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