#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=500+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

struct Point{
    ll x, y;
}p[N];


ll dp[N][N];
ll f[N][N];

void solve()
{
    int n,  k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p + 1, p + n + 1, [&](Point a, Point b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    ll ans = 0;

    for(int i = 1; i <= n; i ++) {
        dp[i][k] = 1;
        for(int j = 0; j <= k; j ++) {
            for(int z = 1; z < i; z ++) {
                if(p[z].x>p[i].x||p[z].y>p[i].y) continue;
                ll d = abs(p[i].x - p[z].x) + abs(p[i].y - p[z].y) - 1;
                if(j + d > k) continue;
                dp[i][j] = max(dp[i][j], dp[z][j + d] + d + 1);
            }
            ans=max(ans,j+dp[i][j]);
        }
    }

    cout << ans << endl;
}

void solve2() {
    int n,  k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p + 1, p + n + 1, [&](Point a, Point b){
        if(a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    ll ans = 0;

    for(int i = 1; i <= n; i ++) {
        dp[i][0] = 1;
        for(int j = 0; j <= k; j ++) {
            for(int z = 1; z < i; z ++) {
                if(p[z].x>p[i].x||p[z].y>p[i].y) continue;
                ll d = abs(p[i].x - p[z].x) + abs(p[i].y - p[z].y) - 1;
                if(j >= d) dp[i][j] = max(dp[i][j], dp[z][j - d] + d + 1);
            }
            ans=max(ans, k - j + dp[i][j]);
        }
    }
    cout << ans << endl;
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
        solve2();
    }
}