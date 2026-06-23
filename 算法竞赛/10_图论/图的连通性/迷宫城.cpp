#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>G(N);

int cnt,dfn;
int num[N],low[N],sccno[N];
stack<int>s;

void dfs(int u)
{
    s.push(u);
    low[u]=num[u]=++dfn;
    for(int i=0;i<G[u].size();i++){
        int v = G[u][i];
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else 
            low[u]=min(low[u],num[v]);
    }

    if(low[u]==num[u]){
        cnt++;
        while(s.size()){
            int v = s.top();s.pop();
            sccno[v]=cnt;
        }
    }
}


void Tarjan(int n)
{
    cnt = dfn = 0;
    memset(sccno , 0,sizeof sccno);
    memset(num , 0,sizeof num);
    memset(low , 0,sizeof low);

    for(int i=1;i<=n;i++){
        if(!num[i])dfs(i);
    }
}

int main()
{
    int n,m,u,v;
    while(cin>>n>>m,n!=0||m!=0){
        for(int i=1;i<=n;i++){
            G[i].clear();
        }

        for(int i=1;i<=m;i++){
            cin>>u>>v;
            G[u].push_back(v);
        }
        Tarjan(n);

        if(cnt==1)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
