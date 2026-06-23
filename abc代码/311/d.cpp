#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=210+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int cnt = 9e7;

char a[N][N];
bool st[N][N][4];


int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

struct gf{
    int x,y;
    int t;
};



void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t;
        }
    }

    //  for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }

    queue<gf>q;
   // st[2][2][1]=true;
   // int x=2,y=2;
    for(int i=0;i<4;i++)
    {
        
            q.push({2,2,i});
        
    }

    while(q.size())
    {

        auto t = q.front();q.pop();

        if(st[t.x][t.y][t.t]==true)continue;
        st[t.x][t.y][t.t]=true;

        int x= t.x+dx[t.t];
        int y= t.y+dy[t.t];

        if(a[x][y]=='.')
        {
            q.push({x,y,t.t});
        }
        else 
        {
            for(int k=0;k<4;k++)
            {
                
                int tx= t.x+dx[k];
                int ty= t.y+dy[k];

                if(a[tx][ty]=='.'){
                    q.push({tx,ty,k});
                }
            }
        }
    }

    ll ans =0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(st[i][j][0]||st[i][j][2]||st[i][j][3]||st[i][j][1])
            {
               // cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return ;
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