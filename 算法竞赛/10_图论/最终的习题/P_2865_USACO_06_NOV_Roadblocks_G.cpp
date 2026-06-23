#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int n,m;
int dis1[N],dis2[N];

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edg[a].push_back({b,w});
        edg[b].push_back({a,w});
    }

    memset(dis1,0x3f,sizeof dis1);
    memset(dis2,0x3f,sizeof dis2);

    queue<PII>q;
    q.push({1,0});
    dis1[1]=0;

    while(q.size()) {
        auto T = q.front();q.pop();
        int u = T.first;
        int w = T.second;

        for(auto t:edg[u]) {
            int v = t.first;
            int p = t.second+w;
            if(p<dis1[v]){
                dis2[v]=dis1[v];
                dis1[v]=p;
                q.push({v,p});
            }
            else if(p!=dis1[v] && p<dis2[v]){
                dis2[v]=p;
                q.push({v,p});
            }
        }
    }

    cout << dis2[n]<<endl;

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