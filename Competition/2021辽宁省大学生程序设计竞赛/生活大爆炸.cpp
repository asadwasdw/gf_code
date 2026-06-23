#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=110+10;
const long long mod=1e18+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


int c[N][N];

void init()
{
    c[1][1]=1;
    c[1][0]=1;
    for(int i=2;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j)c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j]);
        }
    }
}




int C(int n,int i)
{
    //cout<<c[n][i]<<endl;
    return c[n][i];
}





void solve()
{
    init();
    int n,m,t;
    cin>>n>>m>>t;
    int ans = 0;
    for(int i=4;i<t;i++)
    {
        int j = t-i;
        ans+=C(n,i)*C(m,j);
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