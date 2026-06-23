#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<vector<int>>edg(N);
int bx[N];

int cnt = 0;

void dfs(int u,int father,int mx)
{
   // cout<<u<<endl;
    
    mx=max(bx[u],mx);
    mx--;
   // cout<<u<<" "<<mx<<endl;

    if(mx>=0)
    {
        cnt++;
       // cout<<u<<endl;
    }
    for(auto t:edg[u])
    {
        if(t==father)continue;
        dfs(t,u,mx);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        edg[x].push_back(i);
    }

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        bx[x]=max(bx[x],y+1);
    }


    dfs(1,-1,bx[1]);

    cout<<cnt<<endl;



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