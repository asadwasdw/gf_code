#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{

    int n,a,b;
    cin>>n>>a>>b;
    int ans;

    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x==a+b&&ans==0)
        {
            ans=i;
        }
    }

    cout<<ans<<endl;





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