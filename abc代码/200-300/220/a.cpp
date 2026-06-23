#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


void solve()
{
    int a,b,c;

    cin>>a>>b>>c;

    for(int i=c;1;i+=c)
    {
        if(i>=a&&i<=b)
        {
            cout<<i<<endl;
            return ;
        }

        if(i>b)break;
    }

    cout<<"-1"<<endl;



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