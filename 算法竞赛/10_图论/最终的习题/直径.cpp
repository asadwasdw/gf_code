#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int dis[N];
int n;
int idx,h[N],ne[N],e[N],w[N];
int pre[N];
bool zj[N];
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}


int bfs(int x)
{
    memset(dis,0x3f,sizeof dis);
    queue<int>q;
    q.push(x);
    dis[x]=0;
    int tim=10;
    while(q.size()){
        // tim--;
        // if(tim==0)break;
        int u  = q.front();q.pop();
        //cout<<u<<endl;
        for(int i = h[u];~i;i=ne[i]){
            int v =  e[i];
            if(dis[v]!=INF)continue;
            dis[v]=dis[u]+w[i];
            q.push(v);
            pre[v]=i;
        }
    }

    int res = x;
    for(int i=1;i<=n;i++){
       // cout<<dis[i]<<" "<<dis[res]<<endl;
        if(dis[i]>dis[res])res=i;
    }
    //cout<<res<<endl;
    return res;
}

vector<int>dia;

void zdzj(int st,int end)
{
    while(st!=end)
    {
        //cout<<end<<endl;
        dia.push_back(end);
        zj[end]=true;
        end=e[pre[end]^1];
    }
    dia.push_back(st);
    reverse(dia.begin(),dia.end());
   //cout<<st<<endl;
    zj[st]=true;
}

int dfs(int u,int fa)
{
    int res = 0;
    //cout<<ne[0]<<endl;
    for(int i = h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        if(zj[j])continue;

        res = max(res,dfs(j,u)+w[i]);
    }
    //cout<<"s"<<endl;
    return res;
}


void solve()
{
    memset(h,-1,sizeof h);
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
   int p = bfs(1);//起点
   int q = bfs(p);//终点
   cout<<dis[q]<<endl;
   zdzj(p,q);
   //for(auto t:dia)cout<<t<<" ";cout<<endl;
   int l =0,r=0;
    for(int i=0;i<dia.size();i++){
       // cout<<dia[i]<<endl;
        int t = dfs(dia[i],-1);
        int t2 = dis[dia[i]];
        
        if(t==t2){
            l=i;
          // break;
        }
    }


    // for(int i = h[3];~i;i=ne[i]){
    //     cout<<e[i]<<endl;
    // }

    for(int i=dia.size()-1;i>=0;i--){
        int t = dfs(dia[i],-1);
        int t2 = dis[q]-dis[dia[i]];
        //cout<<t<<" "<<t2<<endl;
        if(t==t2){
            r=i;
        }
    }
    //cout<<r<<" "<<l<<endl;
    cout<<r-l<<endl;



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