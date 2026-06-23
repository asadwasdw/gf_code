#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[25][25];
unordered_map<ll,ll> dp[25][25];
unordered_map<ll,ll> dp2[25][25];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }

    dp[1][1][a[1][1]]=1;
    dp2[n][n][a[n][n]]=1;

    // for(auto t:dp[1][1]){
    //     cout<<" "<<t.first<<" "<<dp[1][1][t.first];
    // }


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+j>=n+1)break;
            if(i!=n)
            {
                for(auto t:dp[i][j])
                {
                   // cout<<i<<" "<<j<<" "<<t.first<<" "<<dp[i][j][t.first];
                    dp[i+1][j][a[i+1][j]^t.first]+=t.second;
                }
            }
 
            if(j!=n)
            {
                for(auto t:dp[i][j])
                {
                    dp[i][j+1][a[i][j+1]^t.first]+=t.second;
                }
            }
        }
    }

    for(int i=n;i>=1;i--)
    {
        for(int j=n;j;j--)
        {
            if(i+j<=n+1)break;
            if(i!=1)
            {
                for(auto t:dp2[i][j])
                {
                   // cout<<i<<" "<<j<<" "<<t.first<<" "<<dp[i][j][t.first];
                    dp2[i-1][j][a[i-1][j]^t.first]+=t.second;
                }
            }
 
            if(j!=1)
            {
                for(auto t:dp2[i][j])
                {
                    dp2[i][j-1][a[i][j-1]^t.first]+=t.second;
                }
            }
        }
    }

    ll ans =0;

    for(int i=1;i<=n;i++)
    {
        int j = n+1-i;

        for(auto t:dp[i][j])
        {
            if(i!=n)ans+=t.second*dp2[i+1][j][t.first];
            if(j!=n)ans+=t.second*dp2[i][j+1][t.first];


            // ans+=t.second*dp2[i][j][t.first^a[i][j]];
            // cout<<i<<" "<<j<<" "<<t.first<<" "<<t.second<<" "<<dp2[i][j][t.first]<<endl;
        }
    }

    cout<<ans<<endl;

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