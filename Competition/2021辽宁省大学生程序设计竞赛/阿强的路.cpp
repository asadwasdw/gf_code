#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int N = 5e3 + 50, LOGN = 30;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int>PII;
int ans [N][N];
int v[N];
int edg[N][N]; 
int node[N][N];
int n,m;
PII v2[N];

int get(int x)
{
    if(x<inf)return x;
    return 0;
}
 
 
void f()
{
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int  K = v2[k].second;
            edg[i][j] = min(edg[i][j],max(edg[i][K],edg[K][j]));
            ans[i][j] = min(ans[i][j],edg[i][j]*max({v[i],v[j],v2[k].first}));
        }
    }
}
 
 bool cmp(PII a,PII b)
{
    return a.first<=b.first;
}
  
 
 
void solve(){



    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
                if(i==j)continue;
                edg[i][j]=1e9+7;
                ans[i][j]=1e18+7;
            }
    }
    for(int i=1;i<=n;i++)cin>>v[i],v2[i]={v[i],i};
 
    for(int i=1;i<=m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edg[b][a]=edg[a][b]=min(edg[a][b],w);
       // ans[a][b]=ans[b][a]=min(ans[a][b],edg[a][b]*max(v[a],v[b]));
    }

    sort(v2+1,v2+n+1,cmp);

    f();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)ans[i][j]=0;
            if(ans[i][j]<inf)
                cout<<ans[i][j]<<" ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
