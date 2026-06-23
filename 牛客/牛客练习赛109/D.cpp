#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int mod = 1e9+7 ;

map<long long,long long>mp;

long long qmi(long long a,long long p,long long mod)
{
    long long ans=1;

    while(p)
    {
        if(p&1)ans=ans*a%mod;
        a=a*a;
        a%=mod;
        p>>=1;
    }
    return ans;

}

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;

    }


    while(k--)
    {
        auto t11=mp.begin();
        long long t1=t11->first;mp[t1+m]++;
        auto t22=mp.rbegin();
        long long t2= t22->first;

        
        mp[t2-m]++;
        mp[t1]--;
        mp[t2]--;

        if(!mp[t1])mp.erase(t1); 
        if(!mp[t2])mp.erase(t2); 
    }

    long long ans=1;

    while(mp.size())
    {
        auto t1=mp.begin();
        long long t =t1->first;
        ans=ans*qmi(t,mp[t],mod)%mod;
       // cout<<t<<" "<<mp[t]<<endl;
        mp.erase(t);
    }

    cout<<ans<<endl;

}