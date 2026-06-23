#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m;
int js(int x)
{
    int ans = x%n;
    if(ans==0)ans=n;
    return ans;
}

void solve()
{
  
    cin>>n>>m;
int z = n*m/__gcd(n,m);
if(n==0){
    cout<<"0\n";return;
}
    if((z/n)%2==0){
        cout<<"-1\n";return;
    }


        vector<int>ans;
        for(int i=1;i<=z;i+=m){
           ans.push_back(i);
        }
        cout<<ans.size()<<endl;
        for(auto t:ans)cout<<js(t)<<" ";cout<<"\n";

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