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


double dp[1<<20][20];

double ans =1e18;

void solve()
{

    cin>>n>>m;

    mb = ((1ll<<(n))-1);
    mv = ((1ll<<(n+m))-1)-(mb);

    // cout<<mb<<endl;
    // cout<<V(15)<<endl;

    for(int i=0;i<n+m;i++)
    {
        cin>>no[i].x>>no[i].y;
    }

    for(int i=0;i<(1ll<<20);i++)
    {
        for(int j=0;j<20;j++)dp[i][j] = 1e18 ;
    }

    for(int i=0;i<n+m;i++){
        dp[1<<i][i]=js(no[i],no[19]);
        //cout<<dp[1<<i][i]<<endl;
    }

    for(int s = 0;s<(1<<(n+m));s++)
    {
        double v = V(s);
      //  cout<<s<<" "<<v<<endl;
        for(int i=0;i<n+m;i++)
        {
            if((s>>i)&1){//当前点

            for(int j=0;j<n+m;j++)
            {
                if((s>>j)&1)continue;//下一个点
                //cout<<s<<" "<<(s^(1<<j))<<" "<<i<<" "<<j<<endl;
    
                dp[s|(1<<j)][j]=fmin(dp[s|(1<<j)][j],dp[s][i]+js(no[i],no[j])/v);
            }
            }

        }
    }


    // for(int s = 0;s<(1<<(n+m));s++){
    //     for(int i=0;i<n+m;i++)cout<<dp[s][i]<<" ";cout<<endl;
    // }
    double ans = 1e18;

    for(int s = 0;s<(1<<(n+m));s++){
        double v = V(s);
        if((s&mb)==mb){

            for(int j=0;j<n+m;j++)
            {
                //cout<<s<<" "<<j<<" "<<dp[s][j]<<endl;
                if((s>>j)&1)
                ans = fmin(ans,dp[s][j]+js(no[j],no[19])/v);
            }
        }
    }

 //   cout<<ans<<endl;

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