#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1000+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;




int a[N][N];

void init()
{
  //  a[0][0]=1;
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            
            if(!j)a[i][j]=1;
            else a[i][j]=(a[i-1][j-1]+a[i-1][j])%mod;
            
        }
    }
}


void solve()
{

    int n,m,k;
    cin>>n>>k>>m;

    vector<vector<int>>dp(k+10,vector<int>(n+10,0));

    string s1,s2;
    cin>>s1>>s2;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }

    dp[0][cnt]=1;

    for(int i=0;i<k;i++)
    {
        for(int j=0;j<=n;j++){
            if(!dp[i][j])continue;

            for(int z=0;z<=j;z++)
            {
                int z2 = m - z;
                if(j-z+z2<0)continue;
                if(j-z+z2>n)continue;
                if(z2>n-j)continue;
                if(z2<0)continue;
                dp[i+1][j-z+z2]+=dp[i][j]*a[j][z]%mod*a[n-j][z2]%mod;
                dp[i+1][j-z+z2]%=mod;

            }
        }
    }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)cout<<dp[i][j]<<" ";cout<<endl;
    // }

    cout<<dp[k][0]%mod<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    init();
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}