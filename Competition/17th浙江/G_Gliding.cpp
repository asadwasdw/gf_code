#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int vf,vp,vh;
struct Node{
    int x,y,v;
}node[N];

bool cmp(Node a, Node b) {
    return a.v < b.v;
}

double js(int i,int j) {
    double a = node[i].x - node[j].x;
    double b = node[i].y - node[j].y;
    return sqrt(a*a+b*b)/vh;
}
double dp[N];


void solve()
{
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    cin>>vf>>vp>>vh;
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) cin >> node[i].x >> node[i].y >> node[i].v,dp[i]=INF;
    node[n+1] = {tx,ty,INF};
    dp[0] = 0;
    dp[n + 1] = INF;

    sort(node + 1, node + n + 1, cmp);

    for(int i = 1; i <= n + 1; i++) {
        for(int j = 0; j < i; j ++) {
            if(node[j].v < node[0].v ) continue;
            double t = js(i,j);
            dp[i] = min(dp[i],  t*vp/(node[j].v - vp) + t + dp[j]);
            // cout << t << endl;
        }
        // cout << dp[i] <<" ";
    }
    cout << dp[n + 1] << "\n";


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
}