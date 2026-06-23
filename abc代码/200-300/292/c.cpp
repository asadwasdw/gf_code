#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
const int N=2e5+10;
long long pdh[N];
int f[N];

long long pd(int x)
{
    int ans=1;
    int t=x;
    if(pdh[x])return pdh[x];
   
    for(int i=2;i<=x;i++)
    {
        int num=0;
        if(x%i==0)
        {
            while(x%i==0)
            {
                x/=i;
                num++;
            }
        }
        ans*=num+1;
    }
    if(x>1)ans*=2;
    return pdh[t]=ans;
}


int main()
{
    int n;
    cin>>n;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
        {
            f[j]++;
        }
    }

    int ans1=0;
   int ans2=0;
 
    for(int i=1;i<n;i++)
    {
        ans1+=f[i]*f[n-i];
    }

    cout<<ans1<<endl;


 
  
}