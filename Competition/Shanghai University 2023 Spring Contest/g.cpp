#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


void solve()
{
    int n,m,h,w;
    cin>>n>>m>>h>>w;

    vector<vector<int>>a(n+10,vector<int>(m+10,0));
    vector<vector<int>>s(n+10,vector<int>(m+10,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }

    if(s[n][m]<=0){
        cout<<"NO"<<endl;
        return ;
    }

    for(int i=h;i<=n;i++)
    {
        for(int j=w;j<=m;j++)
        {
            int t=s[i][j]+s[i-h][j-w]-s[i-h][j]-s[i][j-w];
            if(t>=0){
                cout<<"NO"<<endl;
                return;
            }

        }
    }

    cout<<"YES"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}