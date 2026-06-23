#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N];
int dis[1010][25];
int st[1010][25];

void solve()
{
    memset(dis,0x3f,sizeof dis);
    priority_queue<PII,vector<PII>,greater<PII>>q;
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
        if(a[i]==0){
            q.push({1,i});          
            dis[1][i]=0;  
        }
    }

    while(q.size())
    {
        int h = q.top().first;
        int t = q.top().second;q.pop();

        if(st[h][t])continue;
        st[h][t]=true;

        for(int i=1;i<=m;i++){
            if(dis[h][i]>dis[h][t]+abs(i-t)){
                dis[h][i]=dis[h][t]+abs(i-t);
                q.push({h,i});
            }
        }

        int v = h+a[t];
        if( v<1 || v>n )continue;

        if(dis[v][t]>dis[h][t]+2*abs(h-v)){
            dis[v][t]=dis[h][t]+2*abs(h-v);
            q.push({v,t});
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++)cout<<dis[i][j]<<" ";cout<<endl;
    // }
    int ans = INF;
    for(int i=1;i<=m;i++){
        ans=min(dis[n][i],ans);
    }
    if(ans==INF)ans=-1;
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