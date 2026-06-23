#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

typedef unsigned long long ll;
#define int __int128


ll qmi(ll a, ll b)
{
    ll res=1;
    while(b){
        if(b&1)res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}


void solve()
{
    ll res=0;

  //  cout<< qmi(2,10)<<endl;

    for(int i=0;i<64;i++)
    {
        ll x;cin>>x;
        if(x)res+=qmi(2,i);
    }
    cout<<res<<endl;


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