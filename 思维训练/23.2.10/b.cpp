#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

const int N=110;

int a[N][N];
vector<int>ans[N*N];

void solve()
{
  
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%1d",&a[i][j]);
        }
    }

    if(a[1][1]==1){
        cout<<"-1"<<endl;
        return;
    }
    int cs=0;

    for(int i=n;i;i--)
    for(int j=m;j;j--)
    {
        if(a[i][j]==1){
            ans[cs].clear();
            if(j!=1){
                ans[cs].push_back(i);
                ans[cs].push_back(j-1);
            }
            else {
                ans[cs].push_back(i-1);
                ans[cs].push_back(j);
            }
            ans[cs].push_back(i);
            ans[cs].push_back(j);
            cs++;
        }
    }


    cout<<cs<<endl;

    for(int i=0;i<cs;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}