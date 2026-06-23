#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e4+10;
typedef long long ll;

char a[N][N];


char bx(int x)
{
    if(x==1)return '*';
    return '.';
}

void dfs(int x,int y,int cnt,int bj)
{
    if(cnt==1)
    {
        for(int i=0;i<6;i++)
        {
            for(int j=0;j<6;j++)
            {
               // cout<<x+i<<" "<<y+j<<endl;
                if(i>=3&&j>=3)a[x+i][y+j]=bx(1-bj);
                else a[x+i][y+j]=bx(bj);
            }
           
        }
        return ;
    }

    int t=3*pow(2,cnt-1);
    dfs(x,y,cnt-1,1-bj);
    dfs(x,y+t,cnt-1,1-bj);
    dfs(x+t,y,cnt-1,1-bj);
    dfs(x+t,y+t,cnt-1,bj);  
}


void solve()
{
    int n;cin>>n;

    dfs(1,1,n,1);

    int t=3*pow(2,n);
    //cout<<t<<endl;

    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=t;j++){
            cout<<a[i][j];
        }
        cout<<endl;
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