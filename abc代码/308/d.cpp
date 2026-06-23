#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=510;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int bh(char t)
{
    if(t=='s')return 0;
    if(t=='n')return 1;
    if(t=='u')return 2;
    if(t=='k')return 3;
    if(t=='e')return 4;
    return -1;
}

int a[N][N];

int st[N][N];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;cin>>t;
            a[i][j]=bh(t);
           // cout<<a[i][j]<<" ";
        }
     //  cout<<endl;
    }
    queue<PII>q;
    q.push({1,1});

    while(q.size())
    {
        auto t =q.front();q.pop();
        //cout<<t.first<<" "<<t.second<<endl;
        if(st[t.first][t.second])continue;
         st[t.first][t.second]=true;

        for(int k=0;k<4;k++)
        {
            int x=t.first+dx[k];
            int y=t.second+dy[k];

            if(x<1||x>n||y<1||y>m)continue;
           //if(x==2&&y==2&&t.first==1)cout<<(a[x][y]+5-a[t.first][t.second])%5<<endl;
           if((a[x][y]+5-a[t.first][t.second])%5!=1)continue;

            q.push({x,y});
           
        }
    }

    if(st[n][m])cout<<"Yes";
    else cout<<"No";






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