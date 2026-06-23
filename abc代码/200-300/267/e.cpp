#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;


int w[N];

vector<vector<int>>edg(N+1);
typedef pair<int,int>PII;

PII px[N];


priority_queue<PII,vector<PII>,greater<PII>>q;
typedef long long ll;

ll W[N];

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
    }

  

    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;

        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    for(int i=1;i<=n;i++)
    {
        ll res=0;
        for(auto t:edg[i]){
            res+=w[t];
        }
        W[i]=res;
        q.push({res,i});
    }

    ll ans=0;
    int num=0;

    while(num<n)
    {
        auto T = q.top();q.pop();
    
        if(w[T.second]==0)continue;
        num++;
        ans=max(T.first,ans);
        for(auto t:edg[T.second])
        {

            W[t]-=w[T.second];
            q.push({W[t],t});
        }
        w[T.second]=0;
      //  cout<<ans<<endl;
    }

    cout<<ans<<endl;



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