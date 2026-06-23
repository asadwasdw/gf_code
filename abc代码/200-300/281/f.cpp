#include<bits/stdc++.h>
//#define int long long
using namespace std;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int son[N*100][2];
int cs[N*10];
int cnt=1;
void add(ll x)
{
    int p=1;

    for(int i=30;i>=0;i--)
    {
        int t=(x>>i)&1;

        if(!son[p][t]){
            son[p][t]=++cnt;
        }
        p=son[p][t];

    }
}

ll dfs(int cnt,int p)
{
    if(cnt==-1)return 0;
    if(son[p][1]==0)return dfs(cnt-1,son[p][0]);
    if(son[p][0]==0)return dfs(cnt-1,son[p][1]);

   // cout<<(1ll<<cnt)<<endl;

    return min(dfs(cnt-1,son[p][1]),dfs(cnt-1,son[p][0]))+(1ll<<cnt);
}


void solve()
{
    int n;cin>>n;
    //cout<<(1ll<<30)<<endl;

    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        add(x);
    }

   //cout<<cnt<<endl;

    int now=0;

    cout<<dfs(30,1);
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