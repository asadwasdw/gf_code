#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

typedef long long ll;

ll qmi(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a;
        if(res>=1e18)return -1;
        if(res<0)return -1;
        a=a*a;
        b>>=1;
    }
    return res;
}

ll a[100];

void solve()
{

    cin>>a[1]>>a[2];

    int i=3;
    for(;i;i++)
    {
        
        a[i]=qmi(a[i-2],a[i-1]);

        if(a[i]<a[i-1])break;
        if(a[i]>=1e18)break;
        cout<<a[i]<<endl;
    }
    i--;
    cout<<i<<endl;
    


}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}