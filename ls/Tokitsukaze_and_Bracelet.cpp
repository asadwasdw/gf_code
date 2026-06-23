#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans = 0;
    ans+=(a-100)/50;

    if(b<=32)ans+=0;
    else if(b==45)ans+=2;
    else ans+=1;

    if(c<=32)ans+=0;
    else if(c==45)ans+=2;
    else ans+=1;
    
    cout<<ans<<endl;;



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