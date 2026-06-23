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
    int m,k,a1,ak;
    cin>>m>>k>>a1>>ak;

    int mk = m%k;
    int m_k = m/k;

    if(a1>=mk)
    {
        a1-=mk;
        ak += a1/k;
        cout<<max(0,m_k-ak)<<endl;
    }
    else 
    {
        cout<<max(0,m_k-ak)+mk-a1<<endl;;
    }

   // cout<<ans<<endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}