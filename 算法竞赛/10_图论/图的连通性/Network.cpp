#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=100+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
int now =0;
int low[N],num[N];
bool iscut[N];

void dfs(int u,int fa)
{
    ++now;
    low[u]=num[u]=now;
    int child = 0;
    for(int i=0;i<edg[u].size();i++){
        int v = edg[u][i];
        
        if(num[v]==0){
            child++;
            dfs(v,u);
            low[u]= min(low[u],low[v]);
            if(low[v] >= num[u]&&u!=1){
                iscut[u]=true;
            }
        }
        else if(num[v]<num[u])
            low[u]=min(low[u],num[v]);
    }
    //if(u==1)cout<<"s"<<child<<endl;
    if(u==1&&child>=2)
        iscut[1]=true;
    
}


void solve()
{
    int x;
    while(scanf("%d",&x)){
        
        //cout<<x<<endl;
        if(x==0)break;
        while(getchar()!='\n'){
            int y;
            scanf("%d",&y);
            //cout<<x<<" "<<y<<endl;
            edg[x].push_back(y);
            edg[y].push_back(x);
        }
    }
    int ans = 0;
   dfs(1,1);
    for(int i=1;i<=n;i++){
        if(iscut[i])ans++;
        iscut[i]=false;
        low[i]=num[i]=0;
        now=0;
        edg[i].clear();
    }
    cout<<ans<<endl;




}


signed main()
{
    while(scanf("%d",&n)!=-1){
        if(n==0)break;
         solve();
    }
    return 0;
    
}