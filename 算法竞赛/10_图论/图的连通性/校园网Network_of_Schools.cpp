#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int cnt,dfn;
int num[N],low[N],sccno[N];

stack<int>s;


void dfs(int u){
    s.push(u);
    ++dfn;
    low[u]=num[u]=dfn;

    for(auto v:edg[u]){
        if(!num[v]){
            dfs(v);
            low[u]=min(low[v],low[u]);
        }
        else if(!sccno[v]) 
            low[u]=min(low[u],num[v]);
    }

    if(low[u]==num[u]){
        ++cnt;
        while(1)
        {
            int v = s.top();s.pop();
            sccno[v] = cnt;
            if(u==v)
                break;
        }
    }
}

int rd[N],cd[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        while(cin>>x){
            if(x==0)break;
            //cout<<i<<" "<<x<<endl;
            edg[i].push_back(x);
        }
    }
    for(int i=1;i<=n;i++){
        if(!num[i])dfs(i);
    }

    for(int i=1;i<=n;i++){
        for(auto t:edg[i]){
            int x = sccno[i];
            int y = sccno[t];
            if(x==y)continue;
            rd[y]++;
            cd[x]++;
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for(int i=1;i<=cnt;i++){
        if(cd[i]==0)ans2++;
        if(rd[i]==0)ans1++;
    }
    if(cnt==1){
        cout<<ans1<<"\n0"<<endl;
    }
    else 

    cout<<ans1<<"\n"<<max(ans1,ans2)<<endl;






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