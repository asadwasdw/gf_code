#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

long double a[N];

void solve()
{
    int n;cin>>n;
    double sum = 0;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];

    // for(int k=1;k<=500;k++){
    //     for(int i=2;i<=n;i++){
    //         a[i]+=a[i-1]/2;
    //         a[i-1]/=2;
    //     }
    //     a[1]+=a[n]/2;
    //     a[n]/=2;
    // }

    for(int i=1;i<=n;i++)
    {
        a[i]=sum/(n+1);
        if(i==1)a[i]+=a[i];
        printf("%.8Lf ",a[i]);
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