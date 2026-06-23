#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5010;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
typedef long double db;
//vector<vector<int>>edg(N);
db a[N];

bool cmp(db a,db b){
    return a>b;
}
db mx[N];
db dp[N][N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int k = 0;
    db ans = -INF;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            dp[i][j] = max(mx[j-1]*0.9+a[i],dp[i][j]);
            mx[j]=max(mx[j],dp[i][j]);
        }
    }

    db t2=0,t3=1;

    for(int i=1;i<=n;i++){
       // cout<<mx[i]<<" ";
        t2+=t3;
        t3*=0.9;
        ans=max(mx[i]/t2 - 1200/sqrt(i),ans);
    }
    printf("%.15Lf",ans);
   // cout<<ans<<endl;



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