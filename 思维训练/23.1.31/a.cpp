#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#define int long long 
using namespace std;

const int N=2e5+10;
void solve()
{
   

    int a,b,k;
   cin>>a>>b>>k;

  map<int,int>A,B;
    
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        A[x]++;
    }
     for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        B[x]++;
    }

    int ans=k*(k-1)/2;
    for(int i=1;i<=a;i++)
    {
    
        if(A[i]>1)
        {
            ans-=A[i]*(A[i]-1)/2;
           
        }
    }

    for(int i=1;i<=b;i++)
    {
        if(B[i]>1)
        {
            ans-=B[i]*(B[i]-1)/2;
        }
    }

    cout<<ans<<endl;
    
}
signed main()
{
    int t;cin>>t;while(t--)
    solve();
}