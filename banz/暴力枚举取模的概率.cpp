#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll qmi(ll a,ll b,ll c)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res%c;
}


void solve()
{

    ll x;
    cin>>x;

    for(int i=1;i<=500;i++)
    {
        ll t = qmi(i,mod-2,mod);
        for(int j=1;j<=i;j++)
        {
            if(j*t%mod==x){
                cout<<j<<" "<<i<<endl;
            }
        }
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