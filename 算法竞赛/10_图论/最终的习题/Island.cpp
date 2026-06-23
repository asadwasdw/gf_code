#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
vector<vector<PII>>h(N);

int d[N];
int cs[N];
int f[N];
int st[N];
int n;
int w[N];
int find(int x)
{
    if(f[x]!=x)f[x]=find(f[x]);
    return f[x];
}

void typx()
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(d[i]==1){
            d[i]--;
           // cout<<i<<endl;
            q.push(i);
        }
    }

    while(q.size()){
        auto u = q.front();q.pop();
        //cout<<u<<endl;
        for(auto t:edg[u]){
            int v = t.first;
            if(d[v])d[v]--;
            if(d[v]==1)
                q.push(v);
            
        }
    }
}


void print()
{
    for(int i=1;i<=n;i++)cout<<i<<" ";cout<<endl;
    for(int i=1;i<=n;i++)cout<<w[i]<<" ";cout<<endl;
}



int res;

void dfs2(int u,int fa)
{
    int mx1=0,mx2=0;

    for(auto t:edg[u])
    {
        int v = t.first;
        if(d[v]>=2)continue;
        if(v==fa)continue;
        dfs2(v,u);
  
        if(w[v]+t.second>=mx1){
            mx2=mx1;
            mx1=w[v]+t.second;
        }
        else if(w[v]+t.second>mx2){
            mx2=w[v]+t.second;
        }
    }

    res=max(res,mx1+mx2);
    w[u]=mx1;
}


int js(int x)
{
    res = 0;


    for(auto t:h[x]){
        dfs2(t.first,0);

    }

    vector<int>a(h[x].size()*2+10);
    vector<int>b(h[x].size()*2+10);
    int cnt = 0;
    for(auto t:h[x]){
        ++cnt;
        a[cnt]=t.second;
        b[cnt]=w[t.first];
    }
    for(auto t:h[x]){
        ++cnt;
        a[cnt]=t.second;
        b[cnt]=w[t.first];
    }

    // for(int i=1;i<=cnt;i++){
    //     cout<<a[i]<<" ";
    // }cout<<endl;
    // for(int i=1;i<=cnt;i++){
    //     cout<<b[i]<<" ";
    // }cout<<endl;
    for(int i=1;i<=cnt;i++){
        a[i]+=a[i-1];
    }

    priority_queue<PII>q;
    int n = cnt/2;

    for(int i=1;i<=cnt;i++)
    {
        while(q.size()&&abs(q.top().second-i)>=n)q.pop();
        if(q.size()){
            res = max(res,q.top().first+a[i]+b[i]);
        }
        q.push({b[i]-a[i],i});

    }
    //cout<<res<<endl;


    return res;
}

void dfs(int u,int fa,int father)
{
    if(st[u])return;
    st[u]=true;
    //cout<<u<<endl;
    bool ky = 0;

    for(auto t:edg[u]){
        int v = t.first;
        if(v==fa)
        {
            if(ky){
                h[father].push_back({v,t.second});
            }
            ky=1;
            continue;
        }
        if(d[v]<2)continue;
        h[father].push_back({v,t.second});
        dfs(v,u,father);
        break;
    }

}



void solve()
{

    cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        edg[i].push_back({a,b});
        edg[a].push_back({i,b});
        d[i]++;
        d[a]++;
        int fa=find(i);
        int fb = find(a);
        if(fa==fb)continue;
        f[fa]=fb;
    }

    typx();
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        if(d[i]<2)continue;
        if(st[i])continue;
        dfs(i,0,find(i));
    }

    memset(st,0,sizeof st);

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<" xx\n";
    //     for(auto t:h[i])cout<<t<<" ";cout<<endl;
    // }

    for(int i=1;i<=n;i++)
    {
        if(st[find(i)])continue;
        st[find(i)]=true;
        ans+=js(find(i));
    }

    //print();
    cout<<ans<<endl;



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