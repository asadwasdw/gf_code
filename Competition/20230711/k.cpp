#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

struct edg{
    int l,r,w;
}e[N];

bool cmp(edg a,edg b){
    return a.w>b.w;
}

PII query[N];
int ans[N];

bool cmp2(PII a,PII b)
{
    return a.first>b.first;
}
int f[N],sz[N];
int find(int x){
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
        f[i]=i;
        sz[i]=1;
        int l,r,w;
        cin>>l>>r>>w;
        e[i]={l,r,w};
    }

    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        query[i]={x,i};
    }

    sort(e+1,e+m+1,cmp);
    sort(query+1,query+q+1,cmp2);

    ll res=0;

    for(int i=1,j=1;i<=q;i++)
    {
        int t = query[i].first;

        while(j<=m&&e[j].w>=t){

            int l = e[j].l;
            int r = e[j].r;

            j++;
            int fl=find(l);
            int fr=find(r);

            if(fl==fr)continue;

           // res-=(sz[fl])*(sz[fl]-1)/2;
            //res-=(sz[fr]-1)*(sz[fr])/2;
            res+=sz[fr]*sz[fl];

            sz[fr]+=sz[fl];
            f[fl]=fr;
            //res+=(sz[fr]-1)*(sz[fr])/2;
        }

        ans[query[i].second]=res;
    }
    for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}