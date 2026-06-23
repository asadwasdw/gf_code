#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m;
int dis[N];

struct E{
    int id;
    int u,v,c;
    int cost;
}e[N];
int cnt = 0; 

void add(int a,int b,int c,int t)
{
    ++cnt;
    edg[a].push_back(cnt);
    e[cnt]={cnt,a,b,c,t};
}


int bfs()
{
    priority_queue<PII,vector<PII>,greater<PII>>q;
    memset(dis,0x3f,sizeof dis);
    for(auto t:edg[1]){
        int id = e[t].id;
        dis[id]=0;
        q.push({dis[id],id});
    }
    int ans = INF;
    while(q.size())
    {

        auto t = q.top();q.pop();
        int id = t.second;
        int u = e[id].v;

        if(u==n)
        {
             ans=min(ans,t.first+e[id].cost);
        }
        for(auto i:edg[u]){

            int tim = t.first+e[id].cost+abs(e[id].c-e[i].c);

            if(tim<dis[i])
            {
                dis[i]=tim;
                q.push({dis[i],i});
            } 
        }
    }
    return ans;
}



void solve()
{
    
    while(cin>>n>>m){
        cnt = 0;

        for(int i=1;i<=m;i++)
        {
            int a,b,c,t;
            cin>>a>>b>>c>>t;
            add(a,b,c,t);
            add(b,a,c,t);
        }

        cout<<bfs()<<endl;
        for(int i=1;i<=n;i++){
            edg[i].clear();
        }
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