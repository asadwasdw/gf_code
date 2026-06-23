#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


vector<vector<int>>edg(20);

int ST[1ll<<20][20];



bool dfs(ll st,int u)
{
    if(ST[st][u]!=-1)return ST[st][u];
    int cnt =0;
    bool ky = false;
    for(auto t: edg[u])
    {
        if(st>>t&1)continue;
        
        if(!dfs(st+(1ll<<t),t)){
            ky=true;
        }
        
    }
    return ST[st][u] = ky;

}


void solve()
{
    memset(ST,-1,sizeof ST);
    string s[20];
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>s[i];
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            if(s[i][s[i].size()-1]==s[j][0])
            {
                //cout<<i<<" "<<j<<endl;
                edg[i].push_back(j);
            }
        }
    }

    bool ky=false;
    for(int i=1;i<=n;i++)
    {
        ky|=(!dfs(1ll<<i,i));
    }

    if(ky)cout<<"First";
    else cout<<"Second";









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