#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    int n;cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        int t;cin>>t;
        ans+=abs(t);
    }
    cout<<ans*2*n<<endl;
}



int main()
{
    int t;cin>>t;while(t--)
    {
        solve();
    }
}