#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n;
vector<vector<PII>>edg(N);
struct ed
{
    int u,v,w;
}e[N];
int len ;//环长
int st[N];
int a[N];
int b[N];
int cnt=1;
int d[N];
int dd[N];
int zj;
int tppx()
{
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(d[i]==1){
            q.push(i);
        }
    }

    while(q.size())
    {
        int u = q.front();q.pop();
        
        for(auto t:edg[u]){
            int v =t.first;
            d[v]--;
            if(d[v]==1)q.push(v);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++)
    {
        if(d[i]>=2)res=i;
       // cout<<d[i]<<endl;
    }
    cout<<res<<endl;
    return b[1]=res;
}


void dfs(int u,int fa,int len)
{
    st[u]++;
    for(auto t:edg[u])
    {
        int v = t.first;
        if(v==fa)continue;
        if(d[v]<2)continue;
        if(st[v]>=2)continue;

        cnt++;
        a[cnt]=len+t.second;
        b[cnt]=v;

        dfs(v,u,a[cnt]);
        break;
    }
}


int dfs2(int u,int fa)
{
    int mx1 = 0;
    int mx2 = 0;

    for(auto t:edg[u]){
        int v = t.first;
        if(v==fa)continue;
        if(d[v]>=2)continue;

        int w = dfs2(v,u)+t.second;

        if(w>=mx1){
            mx2=mx1;
            mx1=w;
        }
        else if(w>mx2){
            mx2=w;
        }
    }
    zj=max(mx1+mx2,zj);
    return mx1;

}


void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,w;
        cin>>a>>b>>w;
        e[i]={a,b,w};
        edg[a].push_back({b,w});
        edg[b].push_back({a,w});
        d[a]++;
        d[b]++;
    }
    dfs(tppx(),0,0);
    a[1]=a[cnt/2+1]-a[cnt/2];
    for(int i=2;i<=cnt;i++){
        a[i]+=a[1];
    }
    len = a[cnt/2];
    for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";cout<<endl;
    for(int i=1;i<=cnt;i++)cout<<b[i]<<" ";cout<<endl;

    for(int i=1;i<=cnt/2;i++){
        dd[b[i]]=dfs2(b[i],0);
    }

    for(int i=1;i<=cnt/2;i++)cout<<dd[b[i]]<<" ";cout<<endl;
    cout<<zj<<endl;
    cout<<len<<endl;

    priority_queue<PII>q;

    for(int i=1;i<=cnt;i++){

        while(q.size()&&a[i]-a[q.top().second]>=len/2.0)q.pop();

        if(q.size())zj=max(zj,dd[b[i]]+a[i]+q.top().first);
        if(q.size())cout<<i<<" "<<dd[b[i]]+a[i]+q.top().first<<endl;
        q.push({dd[b[i]]-a[i],i});
    }


    cout<<zj/2.0<<endl;







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