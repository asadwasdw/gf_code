#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int N=2e5+10;
 long long a[N];

void solve()
{
    int n;cin>>n;

    long long l=-9999999999;
    long long r=9999999999;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i<=1)continue;

        if(a[i]>a[i-1]){
          long long rt=(a[i]+a[i-1])/2;
            r=min(r,rt);
        }
        else if(a[i]<a[i-1]) {
            long long lt=(a[i]+a[i-1]+1)/2;
            l=max(l,lt);
        }
     //   cout<<i<<" "<<l<<" "<<r<<endl;
    }

    if(l<=r){
        cout<<min(r,(long long)1e9-1)<<endl;
    }
    else cout<<"-1"<<endl;
}


int main()
{
    int t;cin>>t;while(t--)
    solve();
}