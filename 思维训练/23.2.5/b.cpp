#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<long long ,int>st;
const int N=1e5+10;
long long a[N];
bool ky=false;
int cnt;
int primes[N];
bool s[N];

void qie_p(int z)
{
    for(int i=2;i<=z;i++)
    {
        if(!s[i])primes[cnt++]=i;
        
        for(int j=0;primes[j]<=z/i;j++)
        {
            s[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }
}



void fx(int x)
{
    for(int i=0;primes[i]<=x/primes[i];i++)
    {
        if(x%primes[i]==0){
            while(x%primes[i]==0){
                x/=primes[i];
            }
            st[primes[i]]++;
            if(st[primes[i]]>=2)ky=true;
        }
    }
    if(x>1)st[x]++;
    if(st[x]>=2)ky=true;
}

void solve()
{
    st.clear();
    ky=false;
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
       // st[a[i]]++;
        //if(st[a[i]]>=2)ky=true;
    }
    sort(a+1,a+n+1);
    
    for(int i=1;i<=n;i++){
       fx(a[i]);
    }

    if(ky){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;

}

int main()
{
    qie_p(N);
  //  cout<<"s"<<endl;
    int t;cin>>t;while(t--)
    solve();

}