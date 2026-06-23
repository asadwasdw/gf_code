#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=110+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>sz(N);
double c[N];
double dp[N];

void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        int x;
        cin>>x;
        int num0=0;
        for(int j=1;j<=x;j++){
            int t;cin>>t;
            if(t){
                sz[i].push_back(t);
            }
            else num0++;
        }
        c[i]=1.0*c[i] *x/(x-num0);
        //cout<<c[i]<<endl;
    }

    for(int i=m-1;i>=0;i--){
        dp[i] = 1e18;
        for(int j = 1;j<=n;j++){
            double tmp = 0;

            for(auto k:sz[j]){
                tmp+=dp[min(m,i+k)];
            }
            tmp/=sz[j].size();
            tmp+=c[j];
            dp[i]=min(dp[i],tmp);
        }
      //  cout<<i<<" "<<dp[i]<<endl;
    }

    printf("%.16lf",dp[0]);


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