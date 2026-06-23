#include<bits/stdc++.h>
#define int long long
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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    if(n==1||m==1)y=x+1;
    int a = min(n,m)-1;
    int b = max(n,m)-min(n,m);
    //cout<<a<<" "<<b<<endl;
    int ans = min(a*y,2*a*x);
    if(b%2)ans+=x;
    b=b/2*2;
    ans+=min(x,y)*b;
    cout<<ans<<"\n";
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