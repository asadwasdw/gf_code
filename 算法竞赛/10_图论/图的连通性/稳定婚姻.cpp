#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
unordered_map<string,int>id;
int idcnt;

int getid(string s){
    if(!id[s]){
        idcnt++;
        id[s]=idcnt;
    }
    return id[s];
}

PII q[N];



int dfn,cnt;
int low[N],num[N],scc[N];
stack<int>s;

void dfs(int u)
{
    ++dfn;
    s.push(u);
    low[u]=num[u]=dfn;

    for(auto v:edg[u]){
        if(!num[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!scc[v]){
            low[u]=min(low[u],num[v]);
        }
    }

    if(low[u]==num[u]){
        ++cnt;
        while(1){
            int v = s.top();s.pop();
            scc[v]=cnt;
            if(v==u)break;
        }
    }
}





void solve()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        int x=getid(a);
        int y=getid(b);
        q[i]={x,y};
        edg[x].push_back(y);
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        string a,b;
        cin>>a>>b;
        int x=getid(a);
        int y=getid(b);
        edg[y].push_back(x);
    }

    for(int i=1;i<=2*n;i++){
        if(!num[i])dfs(i);
    }

    for(int i=1;i<=n;i++){
        if(scc[q[i].first]==scc[q[i].second]){
            cout<<"Unsafe\n";
        }
        else cout<<"Safe\n";
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