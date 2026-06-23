//https://www.luogu.com.cn/problem/P1403

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;


int main()
{
    int n;cin>>n;

    ll ans=0;

    for( ll l=1,r;l<=n;l=r+1)
    {
        r=(n/(n/l));
        ans+=(n/l)*(r-l+1);
    }

    cout<<ans<<endl;
}