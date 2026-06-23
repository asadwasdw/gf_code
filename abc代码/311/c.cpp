#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int to[N];
int st[N];
ll ans=0;
void dfs(int u,int root)
{
    if(st[u]){
        ans = u;
        return ;
    }
    st[u]=true;
    dfs(to[u],root);
}

vector<int>res;
int num=1;


void dfs2(int u)
{
    if(u==ans)return;
    num++;
    res.push_back(u);
    dfs2(to[u]);
}




void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>to[i];

    for(int i=1;i<=n&&!ans;i++)
    {
        if(!st[i]){
            dfs(to[i],i);
        }
    }
    res.push_back(ans);

    if(ans)
    {
        dfs2(to[ans]);
       //cout<<ans<<endl;
        cout<<num<<endl;
        for(auto t:res)cout<<t<<" ";
    }
    else cout<<"-1"<<endl;



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