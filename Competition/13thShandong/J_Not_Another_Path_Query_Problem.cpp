#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,m,q,v;

int f[N];

int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}

struct query{
    int u,v;
    bool st;
}qu[N];

struct edge{
    int u,v,w;
}e[N];

void check(int x)
{
    if(x==0)return;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        if((e[i].w&x)!=x)continue;
       // cout<<e[i].u<<" "<<e[i].v<<endl;
        int fa = find(e[i].u); 
        int fb = find(e[i].v); 
        if(fa==fb)continue;
        f[fa]=fb;
    }

    for(int i=1;i<=q;i++)
    {
       // cout<<qu[i].u<<" "<<qu[i].v<<endl;
        if(find(qu[i].u)==find(qu[i].v)){
            // if(qu[i].u==2&&qu[i].v==7){
            //     cout<<x<<endl;
            // }
            qu[i].st|=true;
        }
    }


}

void solve()
{

    cin>>n>>m>>q>>v;
    

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }

    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        qu[i]={u,v};
    }
    int T = 0;

    for(int i=60;i>=0;i--)
    {
        int t  = 1ll<<i;
        if((t&v)){
            T+=t;
            continue;
        }
        else {
            check(T+t);
        }

    }

    check(v);

    for(int i=1;i<=q;i++){
        if(qu[i].st)cout<<"Yes\n";
        else cout<<"No\n";
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