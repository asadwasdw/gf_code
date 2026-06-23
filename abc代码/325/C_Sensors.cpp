#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


int n,m;
char a[N][N];
bool st[N][N];

void bfs(int x,int y) {
    queue<PII>q;
    q.push({x,y});

    st[x][y] = true;
    while(q.size()){
        PII u = q.front();q.pop();
        x = u.first;
        y = u.second;

        for(int i = -1;i<=1;i++)
        {
            for(int j = -1;j<= 1;j++){
                int dx = x+i;
                int dy = y+j;

                if(a[dx][dy]!='#')continue;
                if(st[dx][dy])continue;
                 
                q.push({dx,dy});
                st[dx][dy] = true;
            }
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i= 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char t;cin>>t;
            a[i][j] =t;
        }
    }
    int ans = 0;
  //  bfs(1,1);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(st[i][j])continue;
            if(a[i][j] =='#')bfs(i,j),ans++;
        }
    }
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