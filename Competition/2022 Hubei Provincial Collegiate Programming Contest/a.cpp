#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;

typedef long long ll;
ll INF  = 1e16;
int d[550][550];

bool st[N];

struct e
{
    int l,r,w;
};

bool cmp(e a,e b)
{
    return a.w<b.w;
}

int f[N];
int find(int x)
{
    if(x!=f[x])return f[x]=find(f[x]);
    return f[x];
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int t;cin>>t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)d[i][j]=INF;
    }

    for(int i=1;i<=n;i++)f[i]=i;
    int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        d[x][y]=d[y][x]=min(z,d[x][y]);

        int fx=find(x);
        int fy=find(y);
        f[fx]=fy;
    }


    for(int i = 1; i <= n; i++) if(f[i] == i) cnt++;
    //cout<<cnt<<endl;

    if(cnt>1||t==0){
        cout<<"-1"<<endl;
        return ;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

        
    
    vector<int>yy;

    for(int i=1;i<=k;i++){
        int x;cin>>x;
        st[x]=true;
        yy.push_back(x);
    }

    vector<e>edg;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(st[i]&&st[j]){
                edg.push_back({i,j,d[i][j]});
            }
        }
    }

    sort(edg.begin(),edg.end(),cmp);

    for(int i=1;i<=n;i++)f[i]=i;

    int W1 = 0;
    for(auto t: edg)
    {
        int l =t.l;
        int r = t.r;

        int fl=find(l);
        int fr=find(r);
        if(fl==fr)continue;
        W1=max(t.w,W1);
        f[fl]=fr;
    }

    int W2=0;

    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        int ans=INF;
        for(auto t : yy){
           // cout<<t<<endl;
          ans=min(ans,d[t][i]);
        }

        W2=max(W2,ans);
    }
 //   cout<<W1<<" "<<W2<<endl;
    int W = max(W1,W2*2);
  //  cout<<W<<endl;

    cout<<(W+t-1)/t<<endl;
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