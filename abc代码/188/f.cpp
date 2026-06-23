#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

unordered_map<ll,ll>st;
int x,y;


int dfs(int y)
{
    
    if(x>=y)return x-y;
    if(st[y])return st[y];

    int t=y-x;

    if(y%2==1)
    {
        t = min({dfs((y-1))+1,dfs((y+1))+1,t});
    }
    else {
        t =  min(dfs(y/2)+1,t);
    }
    
    st[y]=t;
    return st[y];
}

void solve()
{
    cin>>x>>y;
    cout<<dfs(y)<<endl;
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