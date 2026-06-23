#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
int b[N];
int c[N][N];


void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    for(int i=0;i<=n;i++)c[i][0]=1,c[0][i]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            c[i][j]=(c[i-1][j]+c[i][j-1])%mod;
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=n;j++){
    //         cout<<c[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            int t = abs(a[i]-b[j]);
            ans+=t*(c[i-1][j-1])%mod*(c[n-i][n-j])%mod;
            ans%=mod;
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