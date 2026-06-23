#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll dp[2010][2010];

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)dp[0][i]=1;
  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int l=1;
            if(i!=1){
                l=i*j/(i-1);
            }
            if(i*j==(i-1)*l)l--;//不让a[i]为0

            l=min(l,m);



            while(l>0&&i*j-l*(i-1)<=m)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][l])%mod;
                l--;
            }
        }
    }

    ll res=0;
    for(int i=1;i<=m;i++)res+=dp[n][i];
    cout<<res%mod<<endl;

    // for(int i=1;i<=n;i++)
    // {
    //     int ans=0;
    //     for(int j=1;j<=m;j++)ans+=dp[i][j];
    //     cout<<ans<<" ";
    // }
    

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