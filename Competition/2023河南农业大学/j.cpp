#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

double a[N];

void solve()
{
    int n;cin>>n;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    //cout<<sum<<endl;

    sort(a+1,a+n+1);

    printf("%.6lf %.6lf",(sum-a[n])/(n-1),(sum-a[1])/(n-1));

   // cout<<(sum-a[n])/(n-1)<<" "<<(sum-a[1])/(n-1)<<endl;


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