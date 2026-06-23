#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

const int N =1e4+10;
const int M =1e2+10;
const int NN =N*M;
int s[N][M];


int tr[NN];

void add(int x,int t)
{
    for(int i=x;i<NN;i+= i&-i)tr[i]+=t;
}


int sum(int x)
{
    int res=0;
    for(int i=x;i;i-= i&-i)res+=tr[i];
    return res;
}

void solve()
{

    set<int>a;
    vector<int>x;

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>s[i][j];
            x.push_back(s[i][j]);
        }
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
    	s[i][j] = lower_bound(x.begin(), x.end(), s[i][j]) - x.begin() + 1;
    }

    for(int i=1;i<=m;i++)add(s[n][i],1);

    int ans=0;
    for(int i=n-1;i;i--)
    {
        for(int j=1;j<=m;j++)
        {
            ans+=sum(s[i][j])+(n-i)*j;
        }

        for(int j=1;j<=m;j++)
        {
            add(s[i][j],1);
        }
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