#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    int n;cin>>n;

    for(int i=0;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=9&&!ans;j++)
        {
            if(n%j)continue;
            if(i%(n/j)==0)ans= j;
        }
        if(ans==0)cout<<"-";
        else cout<<ans;
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