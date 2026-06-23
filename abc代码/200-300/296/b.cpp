#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int n=8;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char t;
            cin>>t;
            if(t=='*')
            {
                cout<<char('a'+j-1)<<n-i+1<<endl;
            }
        }
    }



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