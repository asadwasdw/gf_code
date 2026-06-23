#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=510;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int g[N][N];
int d[N*N];
vector<int>ans;

void dfs(int u)
{
    for(int i=1;i<=500;i++){
        if(g[u][i]){
            g[u][i]--;
            g[i][u]--;
            dfs(i);
        }
    }
    ans.push_back(u);
}


void solve()
{
    int n;
    cin>>n;
    int qd=INF;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u][v]++;
        g[v][u]++;
        d[u]++;
        d[v]++;
        qd=min(qd,u);
    }

    for(int i=1;i<=1024;i++)
    {
        if(d[i]%2){
            qd=i;
            break;
        }

    }

    dfs(qd);

    reverse(ans.begin(),ans.end());
    for(auto t:ans)cout<<t<<endl;


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