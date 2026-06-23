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
    int k, d, m, f;
    cin >> k >> d >> m >> f;
    priority_queue<int> K, D, M, F;

    for(int i = 1; i <= k; i ++) {
        int x; cin >> x;
        K.push(x);
    }

    for(int i = 1; i <= d; i ++) {
        int x; cin >> x;
        D.push(x);
    }

    for(int i = 1; i <= m; i ++) {
        int x; cin >> x;
        M.push(x);
    }

    for(int i = 1; i <= f; i ++) {
        int x; cin >> x;
        F.push(x);
    }

    int q;
    cin >> q;
    while(q --) {
        int a, b, c;
        cin >> a >> b >> c;
        int d = 1;
        double sum = 0;
        while(a --) sum += D.top(), D.pop();
        while(b --) sum += M.top(), M.pop();
        while(c --) sum += F.top(), F.pop();
        while(d --) sum += K.top(), K.pop();
        // cout << sum << endl;
        cout << sum / (11.0) << endl;
    }







}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(2) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}