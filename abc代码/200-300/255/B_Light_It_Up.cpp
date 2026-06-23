#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define double long double
//vector<vector<int>>edg(N);

struct node{
    double x,y;
    bool li;

    double len(node t){
        return sqrt((t.x - x) * (t.x - x) +(t.y - y) * (t.y - y));
    }
}
no[N];


void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i = 1;i<=m;i++) {
        int x; cin>>x;
        no[x].li = true;
    }

    for(int i = 1;i<=n;i++) {
        cin>>no[i].x>>no[i].y;
    }
    double ans = 0;

    for(int i=1; i<=n; i++) {
        double res = INF;
        for(int j=1; j<=n ;j++) {
            if(no[j].li)res = min(res,no[i].len(no[j]));
        }
        ans = max(res,ans);
    }
    printf("%.10Lf", ans);
    //cout<<ans<<endl;


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
