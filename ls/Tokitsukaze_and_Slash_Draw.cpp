#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const int N=1e4+10,M=100005;

unordered_map<int,vector<PII>>edge;

int dist[N];
bool st[N];
int n,m,k;


int dijkstra(int s)
{
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    dist[s]=0;


    while(q.size())
    {
        auto t=q.top();q.pop();

        if(st[t.second])continue;
        st[t.second]=true;

        for(auto T:edge[t.second]){
            int to=T.first;
            int w=T.second;
            if(st[to])continue;

            if(dist[to]>t.first+w){
                dist[to]=t.first+w;
                q.push({dist[to],to});
            }

        }
    }
    k=n-k;
    k++;
    if(dist[k]==INFll)return -1;
    else return dist[k];

}



void solve()
{    
    
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {
        edge[i].clear();
        st[i]=false;
        dist[i]=INFll;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int u=1;u<=n;u++) {
            int v = u+a;
            if(v>n)v-=n;
            edge[u].push_back({v,b});
            // cout<<u<<" "<<v<<" "<<b<<endl;
        }
    }

    cout<<dijkstra(1)<<endl;

    // for(int i=1;i<=n;i++)cout<<dist[i]<<" ";


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