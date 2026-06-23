#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=510;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
struct{
    int a,b;
    int u=INFll;
    int d=INFll;
    int l=INFll;
    int r=INFll;
    int flag=false;
    int dis=INFll;
}k[N][N];



void solve()
{
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    int n,m;
    cin>>n>>m;
    int xs,ys,xt,yt;
    cin>>xs>>ys>>xt>>yt;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>k[i][j].a;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>k[i][j].b;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            int x;cin>>x;
            k[i][j].r=k[i][j+1].l=x;
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            int x;cin>>x;
            k[i][j].d=k[i+1][j].u=x;
        }
    }

    q.push({0,xs,ys});

    while(q.size()){
        auto t = q.top();q.pop();
        auto w = t[0];
        int x = t[1];
        int y = t[2];

        if(k[x][y].flag)continue;
        k[x][y].flag=true;

        k[x][y].dis=min(k[x][y].dis,w);
       // cout<<k[x][y].dis<<endl;
        int ab =k[x][y].a+k[x][y].b;
        int tim= w%ab;
        int w1 =0,w2 = 0;
        if(tim<k[x][y].a){
            w1 = k[x][y].a-tim;
        }

        if(tim>=k[x][y].a){
            w2 = ab-tim;
        }

        if(y!=1)q.push({w+k[x][y].l+w1,x,y-1});
        if(y!=m)q.push({w+k[x][y].r+w1,x,y+1});
        if(x!=1)q.push({w+k[x][y].u+w2,x-1,y});
        if(x!=n)q.push({w+k[x][y].d+w2,x+1,y});
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<k[i][j].dis<<" ";cout<<endl;
    // }cout<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<k[i][j].d<<" ";cout<<endl;
    // }
    cout<<k[xt][yt].dis<<endl;
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