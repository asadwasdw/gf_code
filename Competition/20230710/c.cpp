#include<bits/stdc++.h>
#define int long long
//#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

unordered_map<ll,int>st;
int n,m;
vector<vector<int>>edg(N);

int fa[50];
int w[50];
ll ans[50];

ll dp[38][1<<20];

int num[50];
int lsh[50];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>fa[i];
        num[fa[i]]++;
    }

    for(int i=1;i<=n;i++)cin>>w[i];

    int cnt = 0;

    for(int i=1;i<=n;i++)
    {
        if(num[i]>=2)lsh[i]=++cnt;
    }

    //for(int i=1;i<=n;i++)cout<<w[i]<<endl;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        if(a>b)swap(a,b);
        edg[a].push_back(b);
    }

    if(lsh[fa[1]])
        dp[1][1ll<<lsh[fa[1]]]=w[fa[1]];
    else dp[1][0]=w[fa[1]];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1ll<<19);j+=2){
            if(dp[i][j]==0)continue;
            for(auto t:edg[i]){

                int f =fa[t];
                int z = lsh[f];
                //cout<<(1<<z)<<endl;
                if(z==0){
                    dp[t][j]=max(dp[t][j],dp[i][j]+w[f]);
                }
                else if(((j>>z)&1)==0){
                    dp[t][j+(1ll<<z)]=max(dp[t][(1ll<<z)+j],dp[i][j]+w[f]);
                }
                else dp[t][j]=max(dp[t][j],dp[i][j]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        ll res=0;
        for(int j=0;j<(1ll<<19);j+=2){
           // if(dp[i][j])cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            res = max(dp[i][j],res);
        }
        cout<<res<<endl;
    }
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