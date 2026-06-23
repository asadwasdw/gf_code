#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

struct edge
{
    int wd,cd,u;
    inline bool operator > (const edge &x) const {//小根堆，重载大于号，小的在前面
        return cd>x.cd;
    }
};

vector<vector<edge>>edg(N);

struct zb
{
    int x,y;
    void print(){
        cout<<x<<" "<<y<<endl;
    }
}Z[N];


int js(zb a,zb b)
{
    int x =a.x-b.x;
    int y = b.y - a.y;
    return ceil(sqrt(x*x+y*y));
}
int x0,y0,x1,y1,B;
int c[N];
int n;
int too[N][N];
int spee[N][N];
int minw[N],d[N],vis[N][N];

int dj()
{
    priority_queue<edge,vector<edge>,greater<edge>>q;
    for(int i=0;i<=n+2;i++)minw[i]=d[i]=1e9;

    d[n+1]=0;
    minw[n+1]=0;
    q.push({0,0,n+1});


    while(q.size()){
        auto t =q.top();q.pop();
        int wd = t.wd;
        int cd = t.cd;
        int u = t.u;
  

        if(u==n+2)return cd;
        if(vis[u][wd])continue;
        vis[u][wd]=1;//同一个点在同一个距离只跑一次，这样就是1000*100复杂度
  
        for(auto t:edg[u]){
            int wd2 = t.wd;//距离
            int cd2 = t.cd;//碳排放
            int v = t.u;

            //minw[v]最小碳排放下的最近距离
            //d[v]最小碳排放
  
            // 距离，限制条件，有最大值，不能超过最大值，   1
            // 碳排放，要求最小，要在限制1下找到一个最小值    2

            if(wd2+wd>B)continue;//超过限制1
            //cout<<v<<endl;
            //cout<<d[v]<<" "<<cd<<" "<<cd2<<endl;
            if(d[v]>cd+cd2){  //限制2更小，要考虑
                d[v]=cd+cd2;
                minw[v]=wd+wd2;
                q.push({minw[v],d[v],v});
            }
            else if(d[v]==cd+cd2&&wd+wd2<minw[v]){//限制2一样，但限制1更加优秀
                minw[v]=wd2+wd;
                 q.push({minw[v],d[v],v});
            }
            else if(wd2+wd<minw[v]){// 虽然限制2更加大，但是限制更加1优秀，有可能是答案，因为前面的状态可能因为限制1有最大值，而不能跑到终点
                q.push({wd+wd2,cd+cd2,v});
            }
            //最后只剩下限制1和2都更大的，肯定不是答案
        }
    }

    return 1e9;
}

void solve()
{
   
    cin>>x0>>y0>>x1>>y1>>B;
    cin>>c[0];
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];

    cin>>n;
    Z[n+1]={x0,y0};
    Z[n+2]={x1,y1};

    for(int i = 0;i<n;i++)
    {
        cin>>Z[i].x>>Z[i].y;
        cin>>too[i][0];
        for(int j=1;j<=too[i][0];j++){
            cin>>too[i][j]>>spee[i][j];
        }
    }

    for(int i=0;i<n;i++){
        int jl = js(Z[i],Z[n+1]);
        //cout<<i<<" "<<jl<<endl;
      //  Z[i].print();Z[n].print();
        //cout<<endl;
        edg[n+1].push_back({jl,jl*c[0],i});
        jl = js(Z[i],Z[n+2]);
        edg[i].push_back({jl,jl*c[0],n+2});

        for(int j=1;j<=too[i][0];j++){
            jl = js(Z[i],Z[too[i][j]]);
            edg[i].push_back({jl,jl*c[spee[i][j]],too[i][j]});
            edg[too[i][j]].push_back({jl,jl*c[spee[i][j]],i});
        }
    }
    int jl = js(Z[n+1],Z[n+2]);
    edg[n+1].push_back({jl,jl*c[0],n+2});
    int ans = dj();
    if(ans==1e9)ans=-1;
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