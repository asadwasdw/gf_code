#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unsigned long long a[N];

void solve()
{
    unsigned long long n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    unsigned long long ans = 0;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         ans+=(__gcd(a[i]*a[j],k)/__gcd(a[i],k));
    //         cout<<a[i]<<" "<<a[j]<<" "<<__gcd(a[i]*a[j],k)<<endl;
    //     }
    // }

    unsigned long long sum = 0;
    for(int i=1;i<=n;i++){
        sum+=__gcd(a[i],k);
    }

    for(int i=1;i<=n;i++){
        ans+=sum-__gcd(a[i],k)+(__gcd(a[i]*a[i],k)/__gcd(a[i],k));
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