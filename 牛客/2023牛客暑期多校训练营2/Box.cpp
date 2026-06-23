#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N];
int dp[N][3];
int wz[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int num= 0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x){
            num++;
            wz[num]=i;
        }
    }

    dp[1][1]=a[wz[1]];
    if(wz[1]>1){
        dp[1][0]=a[wz[1]-1];
    }
    if(wz[1]<n){
        dp[1][2]=a[wz[1]+1];
    }

    for(int i=2;i<=num;i++)
    {
        for(int j=0;j<=2;j++)
        {
            for(int k=0;k<=2;k++){
                if(wz[i-1]+k-1<wz[i]+j-1&&wz[i]+j-1<=n){
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+a[wz[i]+j-1]);
                }
            }
        }
    }

    cout<<max({dp[num][0],dp[num][1],dp[num][2]});
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