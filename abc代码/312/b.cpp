#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

char a[110][100];

bool check(int x,int y)
{
    x--;
    y--;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[x+i][y+j]=='.')return false;
        }
    }

    for(int i=7;i<=9;i++)
    {
        for(int j=7;j<=9;j++)
        {
            if(a[x+i][y+j]=='.')return false;
        }
    }

    for(int i=1;i<=3;i++)
    {
        if(a[4+x][y+i]=='#')return false;
    }


    if(a[1+x][4+y]=='#')return false;
    if(a[2+x][4+y]=='#')return false;
    if(a[3+x][4+y]=='#')return false;
    if(a[4+x][4+y]=='#')return false;


    for(int i=6;i<=9;i++)
    {
        if(a[6+x][y+i]=='#')return false;
    }

    if(a[7+x][6+y]=='#')return false;
    if(a[8+x][6+y]=='#')return false;
    if(a[9+x][6+y]=='#')return false;

    return true;

}


void solve()
{

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>a[i][j];
    }

    for(int i=1;i<=n;i++)
    {
        if(i+9>n+1)continue;

        for(int j=1;j<=m;j++)
        {
            if(j+9>m+1)continue;

            if(check(i,j))cout<<i<<" "<<j<<endl;
        }
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