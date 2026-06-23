#include<iostream>

using namespace std;

const int N=1e6+10;

int primes[N];
int phi[N];
int st[N];
int cnt;

void ss(int n)
{
    phi[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            phi[i]=i-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            
            if(i%primes[j]==0)
            {
                phi[i*primes[j]]=phi[i]*primes[j];
                break;
            }
          phi[i*primes[j]]=phi[i]*(primes[j]-1);
            
        }
        
    }
}


void solve(int n)
{

    ss(n);
    
   
    long long int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=phi[i]*(n/i);
    }
    cout<<n<<" "<<ans<<endl;
}

int main()
{
    int t;cin>>t;while(t--){
        solve(t);
    }
}