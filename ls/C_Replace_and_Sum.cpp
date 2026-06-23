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
    int n, q;
    cin >> n >> q;
    vector a(n + 1, 0), b(n + 1, 0), s(n + 1, 0);

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        a[i] = max(a[i], b[i]);
    }

    for(int i = n - 1; i >= 1; i --) {
        a[i] = max(a[i + 1], a[i]);
    }

    for(int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + a[i];
    }

    while(q --) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << " ";
    }
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
    return 0;
}