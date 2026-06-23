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
int d[1010][1010];
int a[N];
void solve()
{
    int n, T;
    cin >> n >> T;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) cin >> d[i][j];
    }

    while(T--) {
        int m; cin >> m;
        deque<int> q;
        for(int i = 1; i <= m; i ++) cin >> a[i];
        int ans = 0;

        for(int i = m; i >= 1; i --) {
            while(q.size() && d[a[i]][q.front()] == 1)q.pop_front();
            q.push_front(a[i]);
            ans ^= q.back();
        }
        cout << ans << endl;
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
}