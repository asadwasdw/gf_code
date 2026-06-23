#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

int n,m;
vector<vector<int>>edg(N);
bool st[N];
int low[N],num[N],cnt;
bool iscut[N];
vector<int>ans;

void dfs(int u,int root)
{
    ++cnt;
    low[u]=num[u]=cnt;
    int child = 0;

    for(auto t:edg[u]){
        if(num[t]==0){
            child++;
            dfs(t,root);
            low[u]=min(low[u],low[t]);
            if(low[t]>=num[u]&&u!=root){
                iscut[u]=true;
            }
        }
        else
            low[u]=min(low[u],num[t]);
    }

    if(u==root&&child>=2){
        iscut[u]=true;
    }
}



void solve()
{
    cin>>n>>m;

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(num[i]==0){
            dfs(i,i);
        }
    }
    for(int i=1;i<=n;i++){
        if(iscut[i])ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto t:ans)cout<<t<<" ";

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