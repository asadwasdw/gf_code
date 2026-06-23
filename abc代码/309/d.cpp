#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<vector<int>>edg(N);

int st[N];

int bfs(int u)
{
    queue<int>q;

    q.push(u);
    
    int res=0;

    while(q.size())
    {
        auto T = q.front();q.pop();
        for(auto t : edg[T])
        {
            if(t==u)continue;
            if(st[t])continue;


            st[t]=st[T]+1;
            res=max(res,st[t]);

            q.push(t);
        }
    }
    //cout<<res<<endl;
    return res;
}

void solve()
{
    int n1,n2,m;
    cin>>n1>>n2>>m;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        edg[x].push_back(y);
        edg[y].push_back(x);

    }

    int ans1 = bfs(1);
    int ans2 = bfs(n1+n2);


    cout<<ans1+ans2+1<<endl;




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