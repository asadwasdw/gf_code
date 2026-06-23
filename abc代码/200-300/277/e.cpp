#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;

typedef long long ll;
const ll INF  = 0x3f3f3f3f3f3f3f3f;

bool swi[N];

vector<int> edg[N][2];
ll dis[N][2];

void bfs()
{
    deque<PII>q;
    q.push_back({1,1});
    dis[1][1]=0;

    while(q.size())
    {
        auto t=q.front();q.pop_front();
        int x = t.first;
        int y = t.second;
        for(auto t :edg[x][y]){
            if(dis[t][y]!=INF)continue;
            dis[t][y]=dis[x][y]+1;
            q.push_back({t,y});
        }

        if(swi[x]){
            if(dis[x][y^1]==INF){
                dis[x][y^1]=dis[x][y];
                q.push_front({x,y^1});
            }
        }
    }
}

void solve()
{

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)swi[i]=false;
    memset(dis,0x3f,sizeof dis);

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edg[a][c].push_back(b);
        edg[b][c].push_back(a);
    }

    for(int i=1;i<=k;i++)
    {
        int x;cin>>x;
        swi[x]=true;
    }

    bfs();

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<dis[i][0]<<" "<<dis[i][1]<<endl;
    // }

    ll ans = min(dis[n][1],dis[n][0]);
    if(ans==INF)ans=-1;
    cout<<ans<<endl;







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