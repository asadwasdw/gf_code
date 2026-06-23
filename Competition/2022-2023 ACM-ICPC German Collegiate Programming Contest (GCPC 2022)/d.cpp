#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define int long long 
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


typedef long long ll;


void solve()
{
    int ans=0;
    for(int i=0;i<41;i++)
    {
        cout<<"? ";
        cout.flush();
        int t=1ll<<i;
        cout<<t<<endl;
        cout.flush();
        int x;cin>>x;
        if(x<t)
        {
            ans=t-x;
            break;
        }
    }
    cout<<"! ";
    cout<<ans<<endl;  cout.flush();

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