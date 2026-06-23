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
    vector<int> a(n + 1, 0), p(n + 1, 0), b(n + 1, 0);
    map<int, int>pos;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    bool ky = true;
    int x = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        if(x > pos[a[i]]) {
            ky = false;
        }
        x = max(x, pos[a[i]]);

    }


    if(ky) cout << "YES\n";
    else cout << "NO\n";
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