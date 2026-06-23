#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

struct Point
{
    int x,y;
}p[N],a1,a2;

int len2(Point a, Point b) {
    int x = a.x - b.x;
    int y = a.y - b.y;
    return x * x + y * y;
}

bool cmp(Point a, Point b) {
    return len2(a,a1) < len2(b, a1);
}

void solve()
{
    cin >> a1.x >> a1.y >> a2.x >> a2.y;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> p[i].x >> p[i].y;
    }

    sort(p + 1, p + n + 1, cmp);

    int ans = INF;
    int mx = 0;
    for(int i = n; i; i --) {
        ans = min(ans, mx + len2(a1,p[i]));
        mx = max(len2(a2, p[i]),mx);
        
    }
    ans = min(mx, ans);

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
        solve();
    }
}