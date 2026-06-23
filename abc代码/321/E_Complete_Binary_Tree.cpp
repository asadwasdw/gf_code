#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

typedef unsigned long long ull;

ll N,X,K;
__int128 n,x,k;

ull js(ull u,ull k)
{

    if(u==0)return 0;
    if (k < 0)
        return 0ll;
    if (k >= 64)
        return 0ll;

    ull res = 0;

    __int128 l = u;
    __int128 r = u;

    while(k--&&l&&r)
    {
        l=l*2;
        r=r*2+1;
    }

    if(l>n){
        return 0;
    }
    return min(n,r)-l+1;
}


void solve()
{
    cin>>N;
    cin>>X>>K;

    x=X;
    k=K;
    n=N;

    ull ans = 0 ;
    ans+=js(x,k);
   // cout<<ans<<endl;

    while(x>1&&k)
    {
        if(k==1){
            if(x!=1)ans++;
            break;
        }

        ull t = x^1;
        if (t<=n)ans+=js(t,k-2);
       // cout<<t<<" "<<k-2<<" "<<js(t,k-2)<<endl;
        k--;
        x/=2;
    }
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