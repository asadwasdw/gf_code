#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N];
int dp[310][2050][15];
int n,t,k,m;

int js(int x)
{
    int res = 0;
    while(x)
    {
        x-=x&-x;
        res++;
    }
    return res;
}

void solve()
{
    cin>>n>>t>>k>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[x]++;
    }

    dp[0][0][0]=1;

    int sx = 1<<k;

    for(int i=0;i<t;i++)
    {
        for(int st = 0;st<(1<<k);st++){
            for(int s = 0;s<=n;s++){
                if(dp[i][st][s]==0)continue;
          
                int xz = s+a[i+1];
                int xdst = (st<<1)%sx;
                int tm = js(xdst);

                dp[i+1][xdst][xz]+=dp[i][st][s];
                dp[i+1][xdst][xz]%=mod;

                if(tm<m&&xz){
                    xz--;
                    dp[i+1][xdst+1][xz] += dp[i][st][s]*(xz+1);
                    dp[i+1][xdst+1][xz] %= mod;
                }
            }
        }
    }



    int ans = 0;
    for(int st=0;st<(1<<k);st++)
    {
        //cout<<dp[t][st][0]<<endl;
        ans += dp[t][st][0];
        ans%=mod;
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