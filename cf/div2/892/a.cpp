#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

//https://codeforces.com/contest/1793/problem/A

void solve()
{

    long long a,b;cin>>a>>b;
    long long n,m;cin>>n>>m;

     b=min(a,b);
     long long ans=b*n;
    long long t=n/(m+1);
   // cout<<t<<endl;
    ans=min(ans,(n-t*(m+1))*b+t*m*a);
    cout<<ans<<endl;
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}