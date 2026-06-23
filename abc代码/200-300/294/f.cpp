#include<iostream>
#include<algorithm>
#include<vector>
#define int long long 
using namespace std;
const int N = 4e5+10;

typedef long double ldb;
typedef long long ll;
int n,m,k;
int x1[N],y[N];
int x2[N],y2[N];

long double eps=1e-14;

long double a[N],b[N];

bool check(long double c)
{
    for(int i=1;i<=n;i++)a[i]=(1.0-c)*x1[i]-c*y[i];
    for(int i=1;i<=m;i++)b[i]=(c-1.0)*x2[i]+c*y2[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    int r=1;
    int cnt=0;

    for(int l=1;l<=n;l++)
    {
        while(r<=m&&b[r]<a[l])r++;
        cnt+=r-1;
    }

    return cnt<=k;
}


// bool check(ldb c) {
//     vector<ldb> a(n), b(m);
//     for (ll i = 0; i < n; i++)a[i]=(1.0-c)*x1[i+1]-c*y[i+1];
//     for (ll j = 0; j < m; j++)b[j]=(c-1.0)*x2[j+1]+c*y2[j+1];

//     sort(a.begin(), a.end()), sort(b.begin(), b.end());
//     ll cur = 0, cnt = 0;
//     for (ll i = 0; i < n; ++i) {
//         while (cur < m && b[cur] < a[i])
//             ++cur;
//         cnt += cur;
//     }
//     return cnt <= k;
// }


signed main()
{
    
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)cin>>x1[i]>>y[i];
    for(int j=1;j<=m;j++)cin>>x2[j]>>y2[j];


    long double l=0;
    long double r=1;
    k--;

    while(r-l>eps)
    {
        long double mid=(l+r)/2;
       // cout<<l<<" "<<r<<" "<<mid<<endl;
        if(check(mid))r=mid;
        else l=mid;
    }

    //cout<<l*100<<endl;
    printf("%.14Lf\n", r * 100);

}