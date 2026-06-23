#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<int>ans;
int st[N];

void dfs(int u)
{

    st[u]=true;

    for(auto v :edg[u])
    {
        if(st[v])continue;
        dfs(v);
    }

    if(u!=1)ans.push_back(u);

}




void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        while(x--){
            int j;cin>>j;
            edg[i].push_back(j);
        }
    }
    st[1]=true;
    dfs(1);
    for(auto t:ans)cout<<t<<" ";


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