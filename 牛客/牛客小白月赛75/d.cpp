#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int>PII;
typedef pair<int,PII>PIII;
const int N = 1e6 + 10;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
typedef long long ll;

int a[1010][1010];

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };


int dx2[] = { 1,-1,1,-1 };
int dy2[] = { 1,-1,-1,1 };

int dis[1010][1010];

struct node {
    int d,x, y;
};

void solve()
{

    int n, m;
    cin >> n >> m;

    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char t;
            cin>>t;
            if(t=='1')a[i][j]=1;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //       cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
    q.push({0,1,1,a[1][1]});
    dis[1][1] = 0;

    while (q.size())
    {
        auto T = q.top(); q.pop();
        // cout<<t.x<<" "<<t.y<<endl;
        
        if(T[0]>dis[T[1]][T[2]])continue;

        for (int k = 0; k < 4; k++)
        {
            int x = T[1] + dx[k];
            int y = T[2] + dy[k];
            if (x<1 || x>n || y<1 || y>m)continue;
            int w = 1;
            if (T[3] == a[x][y])w++;

            if (dis[x][y] > T[0] + w)
            {
                dis[x][y] = T[0] + w;
                if(w==1){
                    q.push({dis[x][y],x,y,a[x][y]});
                }
                else{
                    q.push({dis[x][y],x,y,1-a[x][y]});
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dis[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    cout << dis[n][m] << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t; t = 1;
    //cin>>t;
    for (int i = 1; i <= t; i++) {
        //printf("Case %d: ",i);
        solve();
    }
}