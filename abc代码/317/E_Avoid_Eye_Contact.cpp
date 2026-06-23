#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

vector<int>h[2010];
vector<int>l[2010];
char a[2010][2010];
int st[2010][2010];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void solve()
{
    int n,m;
    cin>>n>>m;
    int gx,gy,sx,sy;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t;
            if(t=='<'||t=='>'||t=='^'||t=='#'||t=='v'){
                st[i][j]=-1;
                h[i].push_back(j);
                l[j].push_back(i);         
            }
            if(t=='S'){
                sx=i;
                sy=j;
            }
            if(t=='G'){
                gx=i;
                gy=j;
            }
        }
    }
    

    for(int i=1;i<=n;i++)
    {
        h[i].push_back(0);
        h[i].push_back(m+1);
        a[i][0]='#';
        a[i][m+1]='#';
        st[i][0]=-1;
        st[i][m+1]=-1;
        sort(h[i].begin(),h[i].end());
    }

    for(int i=1;i<=m;i++)
    {
        l[i].push_back(0);
        l[i].push_back(n+1);
        a[0][i]='#';
        a[n+1][i]='#';
        st[0][i]=-1;
        st[n+1][i]=-1;
        sort(l[i].begin(),l[i].end());
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            auto t = upper_bound(h[i].begin(),h[i].end(),j)-h[i].begin()-1;
            int y = h[i][t];

            if(a[i][y]=='>'){
                st[i][j]=-1;
            } 
            y = h[i][t+1];
            if(a[i][y]=='<'){
                st[i][j]=-1;
            }

            t = upper_bound(l[j].begin(),l[j].end(),i)-l[j].begin()-1;
            int x = l[j][t];
            if(a[x][j]=='v')st[i][j]=-1;
            x = l[j][t+1];
            if(a[x][j]=='^')st[i][j]=-1;
        }
    }


    queue<PII>q;
    q.push({sx,sy});
    st[sx][sy]=1;

    while(q.size())
    {
        PII t = q.front();q.pop();

        for(int i=0;i<4;i++){
            int x= t.first+dx[i];
            int y =t.second+ dy[i];

            if(st[x][y]==0)
            {
                st[x][y]=st[t.first][t.second]+1;
                q.push({x,y});
            }
        }
    }
    // for(int i=0;i<=n+1;i++)
    // {
    //     for(int j=0;j<=m+1;j++){
    //         printf("%2d ",st[i][j]);
    //     }
    //     cout<<endl;
    // }
    //if(st[gx][gy]==0)st[gx][gy]=-1;
    cout<<st[gx][gy]-1<<endl;







}


signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}