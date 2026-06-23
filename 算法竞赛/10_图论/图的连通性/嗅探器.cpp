#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int low[N],num[N],dfn;
bool iscut[N];
int v1,v2;

void tj(int u,int fa){
    ++dfn;
    low[u]=num[u]=dfn;

    for(auto v:edg[u]){
        if(!num[v]){

            tj(v,u);
            low[u]=min(low[u],low[v]);
           // cout<<u<<" "<<v<<" "<<num[v2]<<" "<<num[v]<<endl;
            if(low[v]>=num[u]&&fa>0&&num[v2]>=num[v]){
                // 首先保证当前点是一个割点
                // 如果此时num[v2]是0，那么说明v2不在这颗子树内
                // 否则如果下一个点的号大于目标点,说明当前子点不是去目标点的或者已经超过了目标点
                iscut[u]=true;
            }
        }
        else if(num[v]<num[u]&&v!=fa){
            low[u]=min(low[u],num[v]);
        }
    }

    //if(fa<=0&&son>=2)iscut[u]=true;
}

void solve()
{
    int n;cin>>n;
    int x,y;
    while(cin>>x>>y){
        if(x==y&&x==0)break;

        edg[x].push_back(y);
        edg[y].push_back(x);

    }
    cin>>v1>>v2;

    tj(v1,-1);

    // for(int i=1;i<=n;i++){
    //     cout<<i<<" "<<num[i]<<endl;
    // }

    // for(int i=1;i<=n;i++){
    //     if(iscut[i]){
    //         cout<<i<<endl;
    //     }
    // }

    for(int i=1;i<=n;i++){
        if(iscut[i]){
            cout<<i<<endl;
           return;
        }
    }
   puts("No solution");


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