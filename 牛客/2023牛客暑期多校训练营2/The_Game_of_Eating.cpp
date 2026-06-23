#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<priority_queue<PII>>xh(N);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            xh[i].push({x,j});
        }
    }

    bool st[N]={0};

    for(int i=1;i<=k;i++)
    {
        int t = (i)%n;
        if(t==0)t=n;

        while(st[xh[t].top().second]){
            xh[t].pop();
        }
        //cout<<xh[t].top().second<<endl;
        st[xh[t].top().second]=true;
    }
    for(int i=1;i<=m;i++)if(st[i])cout<<i<<" ";cout<<endl;

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