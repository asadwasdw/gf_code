#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,a,b,c;
int d[1100][1100];

int dis[1100][2];
bool st[1100][2];
struct node
{
    int y;
    int x,mark;
    inline bool operator > (const node &x) const {//小根堆，重载大于号，小的在前面
        return y>x.y;
    }
};

void bfs(){
    priority_queue<node,vector<node>,greater<node>> q;
    node s;
    s.mark=0;
    s.y=0;
    s.x=1;
    q.push(s);
    memset(dis,0x3f,sizeof dis);
    dis[1][0] = 0;
    while(q.size()){
        node u = q.top();q.pop();

        if(st[u.x][u.mark])continue;
        st[u.x][u.mark] = true;
       
            if(u.mark == 0) {
                for(int i = 1;i<=n;i++){
    
                    if(dis[i][u.mark] > u.y + d[u.x][i] * a) {
                        dis[i][u.mark] = u.y + d[u.x][i] * a;
                        q.push({dis[i][u.mark],i,u.mark});
                    }
                }

                if(dis[u.x][1] > u.y){
                    dis[u.x][1] = u.y;
                    q.push({u.y,u.x,1});
                }

            }
            else {
                for(int i = 1;i<=n;i++){
                if(dis[i][u.mark] > u.y + d[u.x][i] * b + c) {
                    dis[i][u.mark] = u.y + d[u.x][i] * b + c;
                    q.push({dis[i][u.mark],i,u.mark});
                }
            }
            
        }
    }
}

void solve()
{
    cin>>n>>a>>b>>c;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][j];
        }
    }

    bfs();

    cout<<min(dis[n][1],dis[n][0])<<endl;








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