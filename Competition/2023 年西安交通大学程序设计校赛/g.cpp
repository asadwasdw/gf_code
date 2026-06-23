#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{

    int n;cin>>n;
    int w=0;

    cout<<n-1<<endl;

    for(int i=1;i<n;i++)
    {
        int j=i+1;
        cout<<i<<" "<<j<<" "<<(n+1)*(n+1)/4-i<<endl;

    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}