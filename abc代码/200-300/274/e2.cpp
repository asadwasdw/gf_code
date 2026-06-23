#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
#define double long double

int n,m;
struct node{
    double x,y;
}no[20];

double js(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


int mv;
int mb;

ll V(ll st)
{
    st&=mv;
    int v=0;
    while(st)
    {
        st-= st&-st;
        v++;
    }

    return 1ll<<v;
}

bool cmp(node a,node b)
{
    return js(a,no[0])<=js(b,no[0]);
}


double dp[1<<20][20];

double ans =1e18;


void dfs(ll st,int u)
{
   //cout<<st<<" "<<v<<endl;
    double v = V(st);
    if((st&mb)==mb)
    {
        ans=min(ans,dp[st][u]+js(no[u],no[0])/v);
        //cout<<ans<<" "<<u<<" "<<st<<" "<<dp[st][u]<<endl;
    }

    if(dp[st][u]>ans)return;
    
    int i=1;
    for(;i<=n+m;i++)
    {
        if((st>>i)&1)continue;
      
        double dis = js(no[u],no[i])/v;
        ll t = st+(1ll<<i);
        if(dis+dp[st][u]>dp[t][i])continue;
        //cout<<st<<" "<<v<<endl;
        dp[t][i]=dis+dp[st][u];
        dfs(t,i);
    }
}

void solve()
{

    cin>>n>>m;

    mb = ((1ll<<(n+1))-1);
    mv = ((1ll<<(n+m+1))-1)-(mb);

    //cout<<mv<<endl;
    //cout<<V(15)<<endl;

    for(int i=1;i<=n+m;i++)
    {
        cin>>no[i].x>>no[i].y;
    }

    sort(no+1,no+n+1,cmp);
    sort(no+1+n,no+n+m+1,cmp);

  //  for(int i=1;i<=n+m;i++)cout<<no[i].x<<" "<<no[i].y<<endl;



    for(int i=0;i<(1ll<<20);i++)
    {
        for(int j=0;j<20;j++)dp[i][j] = 1e18;
    }
    dp[1][0]=0;

    dfs(1,0);

    //cout<<ans<<endl;

    printf("%.14Lf",ans);


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