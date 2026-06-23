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

int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = INF;

        // for(int j = 1; j < i; j ++) {
        //     b[i] = min(abs(a[j] - a[i]), b[i]);
        // }

        auto t = s.lower_bound(a[i]);
        if(t != s.end()) {
            b[i] = min(b[i], abs(*t - a[i]));
        }

        
        if(t!=s.begin()) {
            t = prev(t);
            b[i] = min(b[i], abs(*t - a[i]));
        }
        s.insert(a[i]);
    }
    b[1] = a[1];
    ll sum = 0;

    for(int i = 1; i <= n; i ++) {
        sum += b[i];
    }

    cout << sum;






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