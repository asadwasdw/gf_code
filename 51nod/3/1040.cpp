#include<iostream>
#include<algorithm>

using namespace std;

 long long phi(int n)
{
     long long ans=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans=ans*(i-1)/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)
    {
        ans=ans*(n-1)/n;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans+=i*phi(n/i);

            if(i*i!=n)
            {
                ans+=(n/i)*phi(i);
            }

        }

    }
    cout<<ans<<endl;
}