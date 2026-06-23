#include<bits/stdc++.h>
using namespace std;
#define ing long long
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<vector<PII>>edg(N);
int rd[N];
int cs[N];
int cnt;

int dp[N][N][2];
void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edg[a].push_back({b,c});
        rd[b]++;
    }

    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(rd[i]==0)q.push(i);
    }


    while(q.size())
    {
        auto t =q.front();q.pop();

        ++cnt;
        cs[cnt]=t;

        for(auto T :edg[t]){

            rd[T.first]--;
            if(!rd[T.first])
            {
                q.push(T.first);
            }
        }
    }

   // for(int i=1;i<=n;i++)cout<<cs[i]<<" ";cout<<endl;

    memset(dp,0x3f,sizeof dp);
    
    for(int i=1;i<=n;i++)
    {
        int x = cs[i];
        dp[x][x][0]=0;
        for(int j=i;j<=n;j++)
        {
            int y = cs[j];

            for(auto t1:edg[y])
            {
                int z = t1.first;
                ll w = t1.second;

                for(auto c : {dp[x][y][0],dp[x][y][1]}) 
                {
                    c+=w;

                    if(c<dp[x][z][0])
                    {
                        dp[x][z][1]=dp[x][z][0];
                        dp[x][z][0]=c;
                    }
                    else if(c<dp[x][z][1])
                    {
                        dp[x][z][1]=c;
                    }

                }
            }
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<dp[i][j][0]<<" ";
    //     cout<<endl;
    // }

    ll ans = 0x3f3f3f3f3f3f3f3f;
    //int ans =0x3f3f3f3f*2;
   // cout<<ans<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans=min(0ll+ans,0ll+dp[1][i][0]+dp[j][n][0]+dp[i][j][1]+dp[i][j][0]);
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