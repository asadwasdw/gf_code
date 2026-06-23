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
    if(n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector a(n + 1, 0);
    int mid = (n+1)/2;
    int cnt = 1;
    a[mid] = cnt++;
    for(int i = 1; i < mid; i ++) {
        a[mid - i] = cnt++;
        a[mid + i] = cnt++;
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];

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