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
    int n,m;
    cin>>n>>m;
    vector<int>ans;
    while(n&&m){
        //cout<<n/m<<" ";
        ans.push_back(n/m);
        int t = n%m;
        n=m;
        m=t;
    }
    cout<<ans.size()-1<<" ";
    for(auto t:ans)cout<<t<<" ";
    cout<<endl;
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