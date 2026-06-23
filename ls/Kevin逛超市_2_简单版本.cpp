#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

double a[N];

bool cmp(double a,double b) {
    return a > b;
}

void solve()
{
    int n,x,y;cin>>n>>x>>y;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    
    double sum = 0;
    for(int i=3;i<=n;i++) sum += a[i];

    double ans = INF;
    ans = min(a[1]*x/100+max(0.0,a[2]-y),a[2]*x/100+max(0.0,a[1]-y));
    // cout << ans+sum <<endl;
    printf("%.8lf\n",ans+sum);


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}