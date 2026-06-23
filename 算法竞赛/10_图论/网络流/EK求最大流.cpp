#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m,s,t;

int h[N],ne[N],e[N],w[N];
int idx;

int add(int a,int b,int c){
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int pre[N];

int d[N];
bool st[N];

bool bfs()
{
    memset(st,false,sizeof st);
    queue<int>q;
    q.push(s);
    d[s]=INF;
    st[s]=true;

    while(q.size()){
        int u = q.front();q.pop();
       // cout<<u<<endl;
        for(int i = h[u];~i;i=ne[i]){
            int v = e[i];
            if(!st[v]&&w[i]){
                st[v]=true;
                d[v]=min(w[i],d[u]);
                pre[v]=i;
                if(v==t)return true;
                q.push(v);
            }

        }
    }
    return false;
}

int ek()
{
    int ans = 0;
    while(bfs()){
       // cout<<t<<endl;
        int T = t;
        while(T!=s)
        {
            w[pre[T]]-=d[t];
            w[pre[T]^1]+=d[t];
            T = e[pre[T]^1];
        }
        ans+=d[t];
    }
    return ans;
}



void solve()
{
    cin>>n>>m;
    cin>>s>>t;
    memset(h,-1,sizeof h);

    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,0);
    }

    cout<<ek()<<endl;
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