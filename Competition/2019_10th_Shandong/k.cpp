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
    while(b){
        if(b&1)res = res*a%c;
        a=a*a%c;
        b>>=1;
    }
    return res;
}

void solve()
{

    ll a ,p;
    cin>>a>>p;
    ll ans = 0;

    if(a%2){
        cout<<"1"<<endl;
        return;
    }

    for(int i=1;i<p;i++)
    {
        if(qmi(i,a,1ll<<p)==qmi(a,i,1ll<<p))ans+=1;
    }

    int k = (p+a-1)/a;

    ans+=(1ll<<(p-k))-(p-1)/(1<<k);
    cout<<ans<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}