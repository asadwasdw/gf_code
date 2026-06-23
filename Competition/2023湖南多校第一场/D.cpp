#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=5010;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


int f[N][N];
int a[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[0][i]=1;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            
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