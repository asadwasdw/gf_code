#include<iostream>
#include<algorithm>
#define int long long
using namespace std;


signed main()
{

    int n,m;
    cin>>n>>m;

    //f(i)=(f(i-1)+M)%i

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if(ans+m>=i){
            ans+=m;
            ans%=i;
        }
        else{
            int k=min(n-i+1,(i-ans)/m);
            ans+=k*m;i+=k-1;
        }
    }
    cout<<ans+1<<endl;

}