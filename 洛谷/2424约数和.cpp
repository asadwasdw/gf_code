//https://www.luogu.com.cn/problem/P2424

#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

ll js(ll n)
{
    ll res=0;

    for(ll l=1,r;l<=n;l=r+1)
    {
        r=(n/(n/l));

        res+=(n/l)*(l+r)*(r-l+1)/2;
    }
    return res;
}


int main()
{
    ll x,y;

    cin>>x>>y;

    cout<<js(y)-js(x-1)<<endl;

    return 0;
}