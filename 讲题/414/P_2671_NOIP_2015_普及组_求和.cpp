#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e4 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int number[N],color[N];

struct C{
    int xt = 0,x = 0,t = 0;
    int k = 0;
}c[N][2];

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) cin >> number[i];
    for(int i = 1; i <= n; i ++) cin >> color[i];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += c[color[i]][i%2].xt + c[color[i]][i%2].x * number[i] + c[color[i]][i%2].t * i + c[color[i]][i%2].k * i * number[i];

        c[color[i]][i%2].k ++;
        c[color[i]][i%2].xt += i * number[i];
        c[color[i]][i%2].x += i;
        c[color[i]][i%2].t += number[i];
    }

    cout << ans % mod <<endl;   
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