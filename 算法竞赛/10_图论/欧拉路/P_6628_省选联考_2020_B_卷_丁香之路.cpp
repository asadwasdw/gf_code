#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


int n,m,t,s;
int f[N];
int d[N];

int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}


struct edg{
    int u,v,w;
};

bool cmp(edg a,edg b)
{
    return a.w<b.w;
}

vector<edg>e;
int k[N];

void solve()
{
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)f[i]=i;
    ll res = 0;

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        d[u]++;
        d[v]++;

        f[find(u)]=find(v);
        res+=abs(u-v);
    }

    for(int i=1;i<=n;i++)k[i]=find(i);

    for(int i=1;i<=n;i++)
    {
        d[i]++;
        d[s]++;
        for(int i=1;i<=n;i++)f[i]=i;
        f[find(i)]=find(s);

        int lst = -1,free=0;
        for(int j=1;j<=n;j++)
        {
            if((d[j]&1)==0)continue;

            if(lst == -1){
                lst=j;
                continue;
            }

            for(int z = lst;z<j;z++){
                f[find(k[z])]=find(k[z+1]);
            }
            free += j - lst;
            lst = -1;
        }

        e.clear();
        lst = 0;

        for(int j=1;j<=n;j++)
        {
            if(d[j]==0)continue;

            if(lst==0||find(k[lst])==find(k[j])){
                lst=j;
                continue;
            }
            edg now;
            now.u = k[lst];
            now.v = k[j];
            now.w=j-lst;
            e.push_back(now);
            lst=j;
        }

        sort(e.begin(),e.end(),cmp);

        for(auto T:e){
            int u = T.u;
            int v = T.v;
            int w = T.w;

            if(find(u)==find(v))continue;
            f[find(u)]=find(v);
            free+=w*2;
        }

        --d[s];
        --d[i];

        cout<<res+free<<" ";
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