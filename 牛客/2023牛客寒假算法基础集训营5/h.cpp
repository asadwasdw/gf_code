#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    long long x,y,k,n,T;
    cin>>x>>y>>k>>n>>T;
    long long ans=0;
    long long sum=0;

    for(int i=n;i;i--)
    {
        ans+=i*x;
        sum+=i;
        x+=(sum/k)*y;
        sum%=k;
       // cout<<ans<<" "<<x<<endl;

        if(ans>=T)
        {
            cout<<n-i+1<<endl;
            return 0;
        }
    }

     cout<<"-1"<<endl;
}