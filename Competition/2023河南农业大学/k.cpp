#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int a[1010][1010];


int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};


bool pd(int x,int y)
{
    if(a[x][y]!=0)return false;
    int cnt=0;
    for(int i=0;i<4;i++)
    {
        int X = dx[i]+x;
        int Y = dy[i]+y;

        if(a[X][Y]==2)return false;

        if(a[X][Y])cnt++;
        
    }

    return cnt==3;
    
}

void solve()
{
    int n,m;
    cin>>n>>m;



    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char t;
            cin>>t;
            a[i][j]=t-'0';
        }
    }

    int cnt=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pd(i,j))cnt++;
        }
    }

    if(cnt){
        cout<<"YES"<<endl;
        cout<<cnt<<endl;
    }
    else 
    {
        cout<<"NO"<<endl;
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