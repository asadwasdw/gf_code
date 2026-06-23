#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{

    int n;cin>>n;

    long long res=0;

    for(int i=1;i<=n;i++)
    {
        int a;cin>>a;
        if(a>0)
        {
            while(a%2==0)a/=2;
            res+=a;
        }
        else res+=a;
    }

    cout<<res<<endl;




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