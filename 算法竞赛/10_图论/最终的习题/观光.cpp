#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int dis[N][2];
bool st[N][2];
int cnt[N][2];
int d[N];

map<PII,int>dp;
int n,m;

struct node
{
    int id;
    bool type;
    int dist;
    inline bool operator > (const node &x) const {
        return dist>x.dist;
    }
};


void solve()
{

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        d[b]++;
        edg[a].push_back({b,w});
    }

    int s,t;
    cin>>s>>t;
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    memset(st,0,sizeof st);
    cnt[s][0]=1;
    dis[s][0]=0;

    priority_queue<node,vector<node>,greater<node>>q;
    q.push({s,0,0});
    while(q.size()){
        auto t = q.top();q.pop();
        int u = t.id;
        int w = t.dist;
        bool type = t.type;
        if(st[u][type])continue;
        st[u][type]=true;

        for(auto t:edg[u]){
            int v = t.first;
            int w2=w+t.second;

            if(w2<dis[v][0]){
                cnt[v][1]=cnt[v][0];
                dis[v][1]=dis[v][0];
                dis[v][0]=w2;
                cnt[v][0]=cnt[u][type];
                q.push({v,1,dis[v][1]});
                q.push({v,0,dis[v][0]});
            }
            else if(w2==dis[v][0])
            {
                cnt[v][0]+=cnt[u][type];
            }
            else if(w2<dis[v][1]){
                dis[v][1]=w2;
                cnt[v][1]=cnt[u][type];
                q.push({v,1,dis[v][1]});
            }
            else if(w2==dis[v][1]){
                cnt[v][1]+=cnt[u][type];
            }
        }
    }

  //  cout<<dis[t][0]<<" "<<dis[t][1]<<endl;
    int ans = cnt[t][0];
    if(dis[t][1]-1==dis[t][0])ans+=cnt[t][1];
    cout<<ans<<endl;

    for(int i=1;i<=n;i++)
    {
        edg[i].clear();
    }






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