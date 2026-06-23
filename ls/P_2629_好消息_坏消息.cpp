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

int a[N], s[N], l[N], r[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
        l[i] = s[i];
        if(i > 1)l[i] = min(l[i - 1], s[i]);
    }
    for(int i = n; i >= 1; i --) {
        r[i] = s[i];
        if(i < n)r[i] = min(r[i], r[i + 1]);
    }

    int cnt = 0;
    // for(int i = 1; i <= n; i ++) cout << l[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << r[i] << " \n"[i == n];

    for(int k = 1; k <= n; k ++) {
        if(r[k] - s[k - 1] < 0) continue;
        if(l[k - 1] + (s[n] - s[k - 1]) < 0) continue;
        // cout << k << endl;
        cnt ++;
    }

    cout << cnt;








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