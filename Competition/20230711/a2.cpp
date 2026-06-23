#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=5050;
const int mod=998244353;
const int M=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
typedef long long LL; 

int fact[N*N+10], infact[N*N+10];
int qmi(int a,int k,int p)
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=(LL)ans*a%p;
        a=(LL)a*a%p;
        
         k>>=1;
    }
    
    return ans;
}



void init()
{
    // fact[0]=infact[0]=1;
    
    // for(int i=1;i<N*N;i++)
    // {
    //     fact[i]=(LL)fact[i-1]*i%mod;
    //     infact[i]=(LL)infact[i-1]*qmi(i,mod-2,mod)%mod;
    // }


    fact[0]=1;
    for(int i=1;i<N*N;i++){
         fact[i]=fact[i-1]*i%mod;
    }
    //求逆元
    infact[N*N-1]=qmi(fact[N*N-1],mod-2,mod);
    for(int i=N*N-2;i>=0;i--){
       infact[i]=infact[i+1]*(i+1)%mod;
    }
}


int js(int x,int y)
{
    if(y>x) return 0;
    return (LL)fact[x]*infact[y]%M*infact[x-y]%M;
}

void solve()
{ 
    ll n;
    cin>>n;
    ll ans=0;

   // cout<<js(5100,1)<<endl;
  
    for(int i=1;i<=n;i++){
        ans=ans+(js(n*n-i,n-1)%mod);
        //cout<<js(n*n-i,n-1)<<endl;
        //cout<<n*n-i<<" "<<n-1<<" "<<js(n*n-i,n-1)<<endl;
    }
  //  cout<<ans<<endl;
    ans=ans*n%mod*fact[n]%mod*fact[n*(n-1)]%mod;
    cout<<ans<<endl;

}


signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}