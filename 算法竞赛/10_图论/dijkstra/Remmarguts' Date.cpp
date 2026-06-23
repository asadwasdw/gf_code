//https://vjudge.net/problem/POJ-2449

#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;

typedef pair<int,int>PII;

const int INF =0x3f3f3f3f;
const int N=150005,M=100005;

unordered_map<int,vector<PII>>fedge;
unordered_map<int,vector<PII>>edge;

int dist[N];
bool st[N];
int n,m;
void dijkstra(int s)
{
    memset(dist,0x3f,sizeof dist);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    dist[s]=0;


    while(q.size())
    {
        auto t=q.top();q.pop();

        if(st[t.second])continue;
        st[t.second]=true;

        for(auto T:fedge[t.second]){
            int to=T.first;
            int w=T.second;
            if(st[to])continue;

            if(dist[to]>t.first+w){
                dist[to]=t.first+w;
                q.push({dist[to],to});
            }

        }
    }
}

int time[N];

int js(int s,int t,int k)
{
    // 评估函数，A*算法
}







int main()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        fedge[b].push_back({a,c});//反图
        edge[a].push_back({b,c});
    }


}