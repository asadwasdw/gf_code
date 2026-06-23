#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dx[]={-1,-1,0,0,1,1};
int dy[]={-1,0,-1,1,0,1};
int d[5010][5010];
int st[5010][5010];



void bfs(int x,int y)
{
    queue<PII>q;
    q.push({x,y});
    st[x][y]=1;
    while(q.size())
    {
        auto t = q.front();q.pop();
        for(int k=0;k<6;k++)
        {
            x = dx[k]+t.first;
            y = dy[k]+t.second;

            if(x<1||x>5000||y<1||y>5000)continue;

            if(st[x][y])continue;
            if(!d[x][y])continue;
            st[x][y]=1;
            q.push({x,y});
        }

    }

}



void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        a+=2500;
        b+=2500;
        d[a][b]=1;
    }
    int cnt = 0;
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=5000;j++)
        {
            if(!st[i][j]&&d[i][j]){
                bfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

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