#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    if(c>=a&&d>=b)
    {
        cout<<"YES";
        return;
    }

    if(c>=b&&d>=a)
    {
        cout<<"YES";
        return;
    }

    cout<<"NO";



}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}