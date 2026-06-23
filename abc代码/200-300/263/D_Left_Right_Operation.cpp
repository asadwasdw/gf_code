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
int s1[N];
int s2[N];
int dp[N];

void solve()
{
    int n,L,R;
    cin>>n>>L>>R;
    int mn = min(L,R);
    int sum = 0;
    for(int i=1;i<=n;i++)cin>>a[i];


    for(int i=n+1;i;i--){
        s1[i]=s1[i+1]+a[i];
        dp[i]=min(dp[i+1]+a[i],(n-i+1)*R);
    }

    ll ans = INFll; 

    for(int i = 0;i<=n;i++){
        ans = min(ans,i*L+dp[i+1]);
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