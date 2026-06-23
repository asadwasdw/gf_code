#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long f(long long x,long long n)
{
    cout<<n/x<<" "<<x<<endl;
    return n/x+x-1;
}

void solve()
{
    cout<<f(1069128,1145141919810)<<endl;
    long long  n,l,r;
    cin>>n>>l>>r;
    long long t=sqrt(n);
    long long ans=t;

   // cout<<ans<<endl;
    if(f(t+1,n)<f(ans,n))ans=t+1;

    if(t>1){
        if(f(t-1,n)<=f(t,n))ans=t-1;
    }

    
    cout<<ans<<endl;

}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}