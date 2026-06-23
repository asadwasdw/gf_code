#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n,m,k;
vector<vector<int>>edg(N);
bool qp[N][N];
bool st[N];
int match[N];


bool find(int x)
{
    for(auto t:edg[x])
    {
        if(st[t])continue;
        st[t]=true;

        if(match[t]==0||find(match[t])){
            match[t]=x;
            return true;
        }
    }

    return false;
}




void solve()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int a,b;
        cin>>a>>b;
        qp[a][b]=true;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            if(qp[i][j])continue;
            edg[i].push_back(j);
        }
    }
    int ans = 0;

    for(int i=1;i<=n;i++)
    {
        memset(st,0,sizeof st);
        if(find(i))ans++;
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