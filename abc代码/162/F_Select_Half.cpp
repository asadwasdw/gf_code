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

int n;
int a[N];
int s[N];
int dp[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]+=s[i-1];
        if(i%2)s[i]+=a[i];
    }

    for(int i=2;i<=n;i++)
    {
        if(i%2)
        {
            dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        }
        else {
            dp[i]=max(dp[i-2]+a[i],s[i-1]);
        }
    }
    cout<<dp[n]<<endl;
    int i =1 ;
    int t= i++ + ++i;
    cout<<t<<endl;
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