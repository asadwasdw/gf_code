#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;



struct node{
    int x,y;
}zb[N];

struct g{
    int to,x,y;
};

vector<vector<g>>edg(N);
bool st[N];

void dfs(int a)
{
    queue<int>q;
    q.push(a);

    while(q.size())
    {
        int a = q.front();q.pop();
        if(st[a])continue;
        st[a]=true;

        for(auto t:edg[a])
        {
            zb[t.to]={zb[a].x+t.x,zb[a].y+t.y};
            q.push(t.to);
        }
    }

}




void solve()
{
    int n ,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        int x,y;cin>>x>>y;
        
        edg[a].push_back({b,x,y});
        edg[b].push_back({a,-x,-y});
    }

    dfs(1);
    for(int i=1;i<=n;i++)
    {
        if(st[i]==false){
            cout<<"undecidable\n";
        }
        else cout<<zb[i].x<<" "<<zb[i].y<<endl;
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