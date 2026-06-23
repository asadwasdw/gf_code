#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

void solve()
{
    int a[5][5];
    int cnt = 0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            a[i][j]= ++ cnt;
        }
    }

    // for(int i=1;i<=3;i++)
    // {
    //     for(int j=1;j<=3;j++)cout<<a[i][j]<<" ";cout<<endl;
    // }

    int x,y;
    cin>>x>>y;

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[i][j]==x)
            {
                if(a[i][j+1]==y){
                    cout<<"Yes";
                    return ;
                }
            }
        }
    }

    cout<<"No";






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