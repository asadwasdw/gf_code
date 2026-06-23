#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
unordered_map<int,PII>dy;

int a[3][N];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>c;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
        dy[x]={1,i};
    }

    for(int i=1;i<=m;i++)
    {
        int x;
        cin>>x;
        c.push_back(x);
        dy[x]={2,i};
    }

    sort(c.begin(),c.end());

    for(int i=0;i<n+m;i++)
    {
        int x=dy[c[i]].first;
        int y=dy[c[i]].second;

        a[x][y]=i+1;
    }

    for(int i=1;i<=n;i++)cout<<a[1][i]<<" ";
    cout<<endl;
    for(int j=1;j<=m;j++)cout<<a[2][j]<<" ";







}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}