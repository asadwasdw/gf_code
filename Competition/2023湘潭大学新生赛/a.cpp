#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e5+10;
long long a[N];



void solve()
{
    int n,w;
    cin>>n>>w;

    for(int i=1;i<=n;i++)cin>>a[i];

    sort(a+1,a+n+1);
   long long res=0;
    long long i=n;
    for(;i;i--)
    {
        res+=a[i];
        if(res>=w)break;
    }

    cout<<n-i+1<<endl;

    


}

int main()
{
    int t=1;cin>>t;while(t--)
    solve();
    return 0;
}