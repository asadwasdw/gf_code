#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
char a[N][N];
int st[N][N];
int ans = 0;
int sx,sy;
int n,m;

struct Node{
    int x,y;
};
typedef pair<Node,Node>PII;
vector<Node> st2[N][N];

vector<Node> t;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int mn = INF;
int bfs1(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            st[i][j]=false;
    queue<Node>q;
    q.push({sx,sy});
    st[sx][sy]=1;
    int res = 0;

    while(q.size()) {
        auto u = q.front();q.pop();

        for(int k=0;k<4;k++) {
            int x = u.x+dx[k];
            int y = u.y+dy[k];
            
            if(st[x][y])continue;
            st[x][y]=st[u.x][u.y]+1;
            if(x<1||x>n||y<1||y>m)continue;
            if(a[x][y] != '.')continue;
            if(x==1||x==n||y==1||y==m){
                mn=min(mn,st[x][y]);
                res++;
                t.push_back({x,y});
                continue;
            }
            q.push({x,y});
        }
    }
    return res;
}

void bfs2()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            st2[i][j].clear();
    
    queue<PII>q;
    for(auto T:t) {
        q.push({T,T});
    }
  

    while(q.size()) {
        auto u = q.front().first;
        auto root = q.front().second;

        q.pop();
        if(st2[u.x][u.y].size()>=2)continue;
        st2[u.x][u.y].push_back(root);
        if(a[u.x][u.y]=='V')continue;
            for(int k=0;k<4;k++) {
            int x = u.x+dx[k];
            int y = u.y+dy[k];
            if(st2[x][y].size()>=2)continue;
            if(x<1||x>n||y<1||y>m)continue;
            if(a[x][y]  == '#')continue;
            q.push({{x,y},root});
        }
    }
}

bool pd(Node a,Node b)
{
    if(a.x!=b.x || a.y!=b.y)return false;
    return true;
}

void solve()
{

    cin>>n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]=='V'){
                sx=i;
                sy=j;
            }
            if(a[i][j]=='.')ans++;
        }
    }

    int t = bfs1();
    if(t==0){
        cout<<ans<<"\n";
    }
    else if(t==1) {
        cout<<ans - mn + 1 <<"\n"; 
    }
    else {
        bfs2();
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(st2[i][j].size()==2){
                    if(pd(st2[i][j][0],st2[sx][sy][0]) && pd(st2[i][j][1],st2[sx][sy][1])) ans++,cout<<i<<" "<<j<<endl;
                    else if(pd(st2[i][j][0],st2[sx][sy][1])|| pd(st2[i][j][1],st2[sx][sy][0])) ans++,cout<<i<<" "<<j<<endl;
                }
            }
        }
        ans--;
        cout<<st[st2[sx][sy][0].x][st2[sx][sy][0].y] + st[st2[sx][sy][1].x][st2[sx][sy][1].y]<<endl;
        cout<<ans + 2 - st[st2[sx][sy][0].x][st2[sx][sy][0].y] - st[st2[sx][sy][1].x][st2[sx][sy][1].y]<<"\n"; 
    
    }
    cout<<"S\n";
    
    










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