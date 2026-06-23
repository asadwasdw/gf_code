#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

void solve()
{
    map<int,long long>num;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        num[x]++;
    }



    long long ans=0;
    for(int i=1;i<=n-2;i++)
    {
        long long a=i,b=i+1,c=i+2;
        if(num[a]>=1&&num[b]>=1&&num[c]>=1)
        ans+=num[a]*num[b]*num[c];
    }
  
    for(int i=1;i<=n-1;i++)
    {
        long long a=i,b=i+1,c=i+2;
        ans+=num[a]*(num[a]-1)/2*num[b]+num[a]*(num[b]-1)*num[b]/2;
       
        ans+=num[a]*(num[a]-1)/2*num[c]+num[a]*(num[c]-1)*num[c]/2;
       
    }
  \
    for(int i=1;i<=n;i++)
    {
        long long a=i,b=i+1,c=i+2;
        if(num[a]>=3)
        ans+=num[a]*(num[a]-1)*(num[a]-2)/6;
    }



    cout<<ans<<endl;
    
}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}