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

ll a[N], l[N], r[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    stack<int> sl, sr;
    sl.push(0);
    for(int i = 1; i <= n; i ++) {
        while(sl.size() && a[i] <= a[sl.top()]) {
            sl.pop();
        }

        l[i] = l[sl.top()] + (i - sl.top()) * a[i];
        sl.push(i);

        // cout << l[i] << " \n"[i == n];
    }

    sr.push(n + 1);
    for(int i = n; i >= 1; i --) {
        while(sr.size() && a[i] <= a[sr.top()]) {
            sr.pop();
        }
        r[i] = r[sr.top()] + (sr.top() - i) * a[i];
        sr.push(i);
    }

    // for(int i = 1; i <= n; i ++) cout << r[i] << " \n"[i == n];
    ll ans = 0, pos = 0;
    for(int i = 1; i <= n; i ++) {
        ll t = l[i] + r[i] - a[i];
        if(t > ans) {
            ans = t;
            pos = i;
        }
    }
    // cout << pos << endl;

    for(int i = pos - 1; i >= 1; i --) {
        a[i] = min(a[i + 1], a[i]);
    }

    for(int j = pos + 1; j <= n; j ++) {
        a[j] = min(a[j], a[j - 1]);
    }
    for(int i = 1; i <= n; i ++) {
        cout << a[i] << " ";
    }
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