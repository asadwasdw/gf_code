#include<iostream>
#include<algorithm>

using namespace std;
#define int long long 
typedef long long LL;
const int N=5e6+10,M=1e9+7;


int fact[N], infact[N];

int qmi(int a,int k,int p)
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=ans*a%p;
        a=a*a%p;
        k>>=1;
    }
    return ans;
}



int C(int y,int x)
{
    return (y>=x&&x>=0?  fact[y]*infact[x]%M*infact[y-x]%M :0);
}


void solve()
{
  

    int n,R1,R2,r,a,h;

    cin>>n>>R1>>R2>>r>>a>>h;
    int ans=0;

    int p=(R1+r<R2?(R1+r)*(R1+r)%M*qmi(R2*R2%M,M-2,M):1)%M;


    fact[0]=infact[0]=1;
    
    for(int i=1;i<N;i++)
    {
        fact[i]=fact[i-1]*i%M;
      // infact[i]=infact[i-1]*qmi(i,M-2,M)%M;

    }

    infact[N-1]=qmi(fact[N-1],M-2,M)%M;
    for(int i=N-2;i>=0;i--)
    {
        infact[i]=infact[i+1]*(i+1)%M;
    }



    for(int i=1;i<=n;i++)
    {
        if(i*a<h)continue;
        
            //cout<<i<<endl;
            ans+=C(n,i)*qmi(p,i,M)%M*qmi(M+1-p,n-i,M)%M;
            ans%=M;
        
    }
    cout<<C(1,1)<<endl;

    cout<<ans<<endl;


}



signed main()
{
  
    solve();
}




