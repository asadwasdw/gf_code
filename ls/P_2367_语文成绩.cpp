#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N], b[N], s[N];

void solve()
{
    int n, p;
    cin >> n >> p;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    while(p --) {
        int l, r, x;
        cin >> l >> r >> x;
        b[l] += x;
        b[r + 1] -= x;
    }

    for(int i = 1; i <= n; i ++) {
        s[i] = s[i - 1] + b[i];
    }

    int mn = INF;

    for(int i = 1; i <= n; i ++) {
        a[i] += s[i];
        mn = min(a[i], mn);  
    }

    cout << mn;
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