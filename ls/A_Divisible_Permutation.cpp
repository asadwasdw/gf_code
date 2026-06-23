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
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    map<int,int> m;
    m[1] = 1;
    a[n] = 1;
    for(int i = n - 1; i >= 1; i --) {
        int t = a[i + 1] + i;
        if(1 <= t && t <= n && m[t] == 0) {
            a[i] = t;
        } else {
            t = a[i + 1] - i;
            a[i] = t;
        }
        m[t] = 1;
    }

    for(int i = 1; i <= n; i ++) {
        cout << a[i] << " \n"[i == n];
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
    return 0;
}