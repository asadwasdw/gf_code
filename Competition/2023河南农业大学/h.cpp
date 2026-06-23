#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;

typedef long long ll;

const ll INF  = 0x3f3f3f3f3f3f3f3f;

ll dx[]={0,0,-1,1};
ll dy[]={1,-1,0,0};

void solve()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>>dt(n+10,vector<char>(m+10));

    vector<vector<ll>>st(n+10,vector<ll>(m+10,INF));
    vector<vector<ll>>X(n+10,vector<ll>(m+10));



    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>dt[i][j];
        }
    }

    int Q;
    cin>>Q;
    while(Q--)
    {
        ll x,y,t;
        cin>>x>>y>>t;

        X[x][y]=t;
    }
    



    queue<PII>q;
    st[1][1]=0;
    q.push({1,1});

    while(q.size())
    {
        auto t = q.front();q.pop();
        //cout<<t.first<<" "<<t.second<<endl;

        if(dt[t.first][t.second]=='*'){
            int T = X[t.first][t.second];
            for(int k =0;k<4;k++){
            if(T>n&&T>m)continue;
            ll tx = t.first+dx[k]*T;
            ll ty = t.second+ dy[k]*T;

            if(tx<1||tx>n||ty<1||ty>m)continue;
            if(dt[tx][ty]=='#')continue;
            if(st[tx][ty]<=st[t.first][t.second])continue;

            st[tx][ty] = st[t.first][t.second];

            q.push({tx,ty});
            }
        }
        else {
            for(int k = 0;k<4;k++){
            
            ll tx = t.first+dx[k];
            ll ty = t.second+ dy[k];

            if(tx<1||tx>n||ty<1||ty>m)continue;
            if(dt[tx][ty]=='#')continue;
            
            if(st[tx][ty]<=st[t.first][t.second]+1)continue;
           // cout<<tx<<" "<<ty<<endl;
            st[tx][ty] = st[t.first][t.second]+1;

            q.push({tx,ty});
        }
        }
    }

    if(st[n][m]==INF)st[n][m]=-1;

    cout<<st[n][m]<<endl;

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