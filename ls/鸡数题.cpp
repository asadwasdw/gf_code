#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

typedef long long ll;

const int N = 100010, mod = 1e9 + 7;



ll Inv[N], fac[N];  //分别表示逆元和阶乘
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init(){
    //求阶乘
    fac[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    //求逆元
    Inv[N-1]=qmi(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--){
        Inv[i]=Inv[i+1]*(i+1)%mod;
    }
}
 
ll C(int n,int m){
    if(m>n){
        return 0;
    }
    if(m==0)
        return 1;
    return fac[n]%mod*Inv[m]%mod*Inv[n-m]%mod;
}


int g[N];
signed main()
{
    init();
    int n,m;
    cin>>n>>m;

    int ans = 0;
    for(int i=m;i<=n;i++) {
        ans = ans + C(i-2,m-2)*qmi(m,n-i)%mod;
        ans%=mod;
        cout<<ans<<endl;
    }
    cout<<ans%mod<<endl;
    return 0;
}
