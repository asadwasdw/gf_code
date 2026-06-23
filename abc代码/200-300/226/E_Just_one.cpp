#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int st[N];
int cnt = 0;


void dfs(int u,int fa){
    
    st[u]=1;

    for(auto v:edg[u]){
        if(v==fa)continue;

        if(!st[v]){
            dfs(v,u);
        }
        else if(st[v]==1){
            cnt++;
        }

    }


    st[u]=2;
}


ll qmi(ll a,ll b,ll c){
    ll res = 1;
    while(b){
        if(b&1)res= res*a%c;
        b>>=1;
        a=a*a%c;
    }
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(st[i])continue;


        dfs(i,0);

        if(cnt!=1){
            cout<<"0\n";
            return;
        }
        ans++;
        cnt= 0;
    }
   // cout<<ans<<endl;

    cout<<qmi(2,ans,mod);


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