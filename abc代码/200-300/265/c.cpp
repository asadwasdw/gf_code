#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

char a[510][510];
int st[510][510];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    int x=1,y=1;

    while(1)
    {
        int tx=x;
        int ty=y;
        
        if(a[x][y]=='U')tx--;
        if(a[x][y]=='D')tx++;
        if(a[x][y]=='L')ty--;
        if(a[x][y]=='R')ty++;

        if(tx<1||tx>n||ty>m||ty<1){
            cout<<x<<" "<<y<<endl;
            return ;
        }
        if(st[x][y]){
            cout<<"-1"<<endl;
            return;
        }
        st[x][y]=1;
        x=tx;
        y=ty;
    }
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